# 🎨 Image Importer for Geometry Dash

[![Geode](https://img.shields.io/badge/Geode-4.9.0-00C7FF?logo=geometrydash)](https://geode-sdk.org)
[![Version](https://img.shields.io/badge/version-1.0.0-blue)]()
[![License](https://img.shields.io/badge/license-MIT-green)]()

> **Transform any image into pixel art directly in your Geometry Dash levels!**

![Banner](https://via.placeholder.com/800x200/1a1a2e/16213e?text=Image+Importer)

## ✨ Features

| Feature | Description |
|---------|-------------|
| 🖼️ **Multiple Formats** | PNG, JPG, JPEG, BMP support |
| 🎯 **Quality Presets** | Low, Medium, High detail levels |
| 👁️ **Live Preview** | See your image before importing |
| ⚡ **Fast Processing** | Optimized for performance |
| 🎨 **True Colors** | Accurate RGB to GD conversion |
| 💡 **Modern UI** | Clean, intuitive interface |

## 📦 Installation

### Method 1: Geode In-Game (Recommended)
1. Open Geometry Dash with Geode installed
2. Click the Geode button on main menu
3. Go to "Download" tab
4. Search for "Image Importer"
5. Click "Install" and restart

### Method 2: Manual Installation
1. Download the latest `.geode` file from [Releases](https://github.com/Nopro497138/Image-Importer/releases)
2. Place in `GeometryDash/geode/mods/` folder
3. Restart Geometry Dash

## 🎮 Usage

1. **Open Editor** - Launch any level in the editor
2. **Click "IMG"** - Find the button on the left side
3. **Select Image** - Browse and choose your file
4. **Pick Quality** - Choose Low/Medium/High
5. **Import** - Click "Import to Level"

## 📊 Quality Settings
```
┌─────────┬──────────────┬──────────┬────────┐
│ Quality │ Sample Rate  │ Objects  │ Speed  │
├─────────┼──────────────┼──────────┼────────┤
│ Low     │ 8x8 pixels   │ ~100     │ ⚡ Fast │
│ Medium  │ 4x4 pixels   │ ~500     │ 🔄 OK   │
│ High    │ 2x2 pixels   │ ~2000    │ 🐌 Slow │
└─────────┴──────────────┴──────────┴────────┘
```

## 💡 Best Practices

### ✅ Do
- Start with **Low** quality for testing
- Use images under 500x500 pixels
- Save your level before importing
- Test with simple images first

### ❌ Don't
- Import huge images on High quality
- Forget to save before importing
- Use High detail for backgrounds
- Import without testing first

## 🔧 Building from Source

### Prerequisites
```bash
# Required tools
- CMake 3.21+
- C++20 compiler
- Geode SDK
- Git
```

### Build Steps
```bash
# Clone repository
git clone https://github.com/Nopro497138/Image-Importer.git
cd Image-Importer

# Configure and build
geode build

# Install to GD
geode package install
```

### Development
```bash
# Clean build
rm -rf build && geode build --clean

# Build for specific platform
geode build --platform win
geode build --platform android
geode build --platform mac
```

## 📸 Screenshots

### Main Interface
The sleek, modern popup interface with real-time preview.

### Quality Comparison
See the difference between Low, Medium, and High settings.

### In-Game Result
Your imported pixel art directly in the level!

## 🎯 Technical Specifications

| Specification | Value |
|--------------|-------|
| **Supported Formats** | PNG, JPG, JPEG, BMP |
| **Max Image Size** | 1000x1000 (recommended) |
| **Object Type** | Square Block (ID: 1) |
| **Color Method** | Direct RGB→ccColor3B |
| **Spawn Position** | (150, 150) |
| **Pixel Spacing** | 1.0 units |
| **Alpha Threshold** | < 50 = transparent |

## 🐛 Known Issues

- Large images (>1000x1000) may cause lag
- No automatic object grouping
- No undo for bulk operations
- High detail can create 5000+ objects

## 🗺️ Roadmap

- [ ] Object grouping feature
- [ ] Custom color palettes
- [ ] Dithering options
- [ ] Batch import
- [ ] Preview grid
- [ ] Export templates

## 🤝 Contributing

Contributions are welcome! Please:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## 📝 License

This project is licensed under the MIT License - see LICENSE file.

## 💬 Support

- **Issues**: [GitHub Issues](https://github.com/Nopro497138/Image-Importer/issues)
- **Discussions**: [GitHub Discussions](https://github.com/Nopro497138/Image-Importer/discussions)
- **Discord**: [Geode Discord Server](https://discord.gg/geode)

## 🙏 Acknowledgments

- Geode SDK Team for the amazing framework
- Geometry Dash community for inspiration
- Contributors and testers

## 📊 Stats

![GitHub stars](https://img.shields.io/github/stars/Nopro497138/Image-Importer)
![GitHub issues](https://img.shields.io/github/issues/Nopro497138/Image-Importer)
![GitHub downloads](https://img.shields.io/github/downloads/Nopro497138/Image-Importer/total)

---

**⭐ If you like this mod, please star the repository!**

**Made with ❤️ by Noahjo**
