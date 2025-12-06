#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

// Enum for detail levels
enum class DetailLevel {
    Low,
    Medium,
    High
};

// Image Import Popup
class ImageImportPopup : public Popup<> {
protected:
    CCSprite* m_previewSprite = nullptr;
    CCLabelBMFont* m_selectedImageLabel = nullptr;
    std::string m_selectedImagePath;
    DetailLevel m_detailLevel = DetailLevel::Medium;
    CCMenu* m_detailMenu = nullptr;

    bool setup() override {
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        
        this->setTitle("Image Importer");

        // Create main content layer
        auto contentLayer = CCLayer::create();
        
        // Select Image Button
        auto selectImageBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Select Image", "goldFont.fnt", "GJ_button_01.png", 0.8f),
            this,
            menu_selector(ImageImportPopup::onSelectImage)
        );
        selectImageBtn->setPosition({0, 80});

        // Detail level buttons
        auto lowBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Low", "bigFont.fnt", "GJ_button_04.png", 0.6f),
            this,
            menu_selector(ImageImportPopup::onDetailLow)
        );
        lowBtn->setPosition({-80, 30});

        auto mediumBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Medium", "bigFont.fnt", "GJ_button_04.png", 0.6f),
            this,
            menu_selector(ImageImportPopup::onDetailMedium)
        );
        mediumBtn->setPosition({0, 30});

        auto highBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("High", "bigFont.fnt", "GJ_button_04.png", 0.6f),
            this,
            menu_selector(ImageImportPopup::onDetailHigh)
        );
        highBtn->setPosition({80, 30});

        // Detail level label
        auto detailLabel = CCLabelBMFont::create("Detail Level:", "bigFont.fnt");
        detailLabel->setScale(0.5f);
        detailLabel->setPosition({winSize.width / 2, winSize.height / 2 + 50});
        this->m_mainLayer->addChild(detailLabel);

        // Selected image label
        m_selectedImageLabel = CCLabelBMFont::create("No image selected", "chatFont.fnt");
        m_selectedImageLabel->setScale(0.7f);
        m_selectedImageLabel->setPosition({winSize.width / 2 + 150, winSize.height / 2 + 80});
        m_selectedImageLabel->setAnchorPoint({0, 0.5f});
        this->m_mainLayer->addChild(m_selectedImageLabel);

        // Preview sprite placeholder
        m_previewSprite = CCSprite::create();
        m_previewSprite->setPosition({winSize.width / 2 + 150, winSize.height / 2});
        m_previewSprite->setVisible(false);
        this->m_mainLayer->addChild(m_previewSprite);

        // Import button
        auto importBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Import", "goldFont.fnt", "GJ_button_01.png", 0.8f),
            this,
            menu_selector(ImageImportPopup::onImport)
        );
        importBtn->setPosition({0, -60});

        // Create menu
        m_detailMenu = CCMenu::create();
        m_detailMenu->addChild(selectImageBtn);
        m_detailMenu->addChild(lowBtn);
        m_detailMenu->addChild(mediumBtn);
        m_detailMenu->addChild(highBtn);
        m_detailMenu->addChild(importBtn);
        m_detailMenu->setPosition({winSize.width / 2, winSize.height / 2});
        
        this->m_mainLayer->addChild(m_detailMenu);

        return true;
    }

    void onSelectImage(CCObject*) {
        file::FilePickOptions options;
        options.filters.push_back({"Image Files", {"*.png", "*.jpg", "*.jpeg", "*.bmp"}});
        
        file::pickFile(file::PickMode::OpenFile, options, [this](Result<std::filesystem::path> result) {
            if (result.isOk()) {
                m_selectedImagePath = result.unwrap().string();
                auto filename = std::filesystem::path(m_selectedImagePath).filename().string();
                m_selectedImageLabel->setString(filename.c_str());
                
                // Try to load preview
                auto texture = CCTextureCache::sharedTextureCache()->addImage(m_selectedImagePath.c_str());
                if (texture) {
                    m_previewSprite->setTexture(texture);
                    auto size = texture->getContentSize();
                    float scale = std::min(100.0f / size.width, 100.0f / size.height);
                    m_previewSprite->setScale(scale);
                    m_previewSprite->setVisible(true);
                }
            }
        });
    }

    void onDetailLow(CCObject*) {
        m_detailLevel = DetailLevel::Low;
        Notification::create("Detail: Low", NotificationIcon::Success)->show();
    }

    void onDetailMedium(CCObject*) {
        m_detailLevel = DetailLevel::Medium;
        Notification::create("Detail: Medium", NotificationIcon::Success)->show();
    }

    void onDetailHigh(CCObject*) {
        m_detailLevel = DetailLevel::High;
        Notification::create("Detail: High", NotificationIcon::Success)->show();
    }

    void onImport(CCObject*) {
        if (m_selectedImagePath.empty()) {
            FLAlertLayer::create("Error", "Please select an image first!", "OK")->show();
            return;
        }

        // Process the image
        processImage();
        this->onClose(nullptr);
    }

    void processImage() {
        auto texture = CCTextureCache::sharedTextureCache()->addImage(m_selectedImagePath.c_str());
        if (!texture) {
            FLAlertLayer::create("Error", "Failed to load image!", "OK")->show();
            return;
        }

        // Get image dimensions
        auto size = texture->getContentSize();
        int width = static_cast<int>(size.width);
        int height = static_cast<int>(size.height);

        // Calculate sampling rate based on detail level
        int sampleRate = 1;
        switch (m_detailLevel) {
            case DetailLevel::Low: sampleRate = 8; break;
            case DetailLevel::Medium: sampleRate = 4; break;
            case DetailLevel::High: sampleRate = 2; break;
        }

        // Get pixel data
        CCImage* image = new CCImage();
        image->initWithImageFile(m_selectedImagePath.c_str());
        unsigned char* data = image->getData();

        // Get editor
        auto editor = LevelEditorLayer::get();
        if (!editor) return;

        // Create objects based on pixels
        int objectCount = 0;
        for (int y = 0; y < height; y += sampleRate) {
            for (int x = 0; x < width; x += sampleRate) {
                int idx = (y * width + x) * 4;
                
                unsigned char r = data[idx];
                unsigned char g = data[idx + 1];
                unsigned char b = data[idx + 2];
                unsigned char a = data[idx + 3];

                // Skip transparent pixels
                if (a < 50) continue;

                // Create a colored square object (ID 1)
                auto obj = GameObject::createObject(1, {static_cast<float>(x), static_cast<float>(height - y)});
                if (obj) {
                    // Set color
                    obj->setObjectColor({r, g, b});
                    editor->addObject(obj);
                    objectCount++;
                }
            }
        }

        image->release();

        std::string msg = "Imported " + std::to_string(objectCount) + " objects!";
        Notification::create(msg, NotificationIcon::Success)->show();
    }

public:
    static ImageImportPopup* create() {
        auto ret = new ImageImportPopup();
        if (ret && ret->initAnchored(400.f, 280.f)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

// EditorUI Hook
class $modify(MyEditorUI, EditorUI) {
    bool init(LevelEditorLayer* lel) {
        if (!EditorUI::init(lel)) return false;

        // Add custom tab button
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        
        auto imageTabBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Image Import", "goldFont.fnt", "GJ_button_05.png", 0.8f),
            this,
            menu_selector(MyEditorUI::onImageImportTab)
        );
        
        // Position the button in the editor UI
        imageTabBtn->setPosition({winSize.width - 50, winSize.height - 50});
        
        // Find or create a menu to add the button to
        auto menu = this->getChildByID("editor-buttons-menu");
        if (!menu) {
            menu = CCMenu::create();
            menu->setPosition({0, 0});
            menu->setID("editor-buttons-menu");
            this->addChild(menu);
        }
        
        static_cast<CCMenu*>(menu)->addChild(imageTabBtn);

        return true;
    }

    void onImageImportTab(CCObject*) {
        ImageImportPopup::create()->show();
    }
};
