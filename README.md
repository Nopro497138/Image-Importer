# 🎨 Image Importer for Geometry Dash

[![Geode](https://img.shields.io/badge/Geode-4.9.0-00C7FF?logo=geometrydash&logoColor=white)](https://geode-sdk.org)
[![Version](https://img.shields.io/badge/version-1.0.0-blue)](https://github.com/Nopro497138/Image-Importer/releases)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![Downloads](https://img.shields.io/github/downloads/Nopro497138/Image-Importer/total)](https://github.com/Nopro497138/Image-Importer/releases)

> **🚀 Transform any image into pixel art with a professional, modern interface!**

![Header](https://via.placeholder.com/800x200/0f0f1e/16213e?text=Image+Importer+%7C+Professional+Pixel+Art+Converter)

## ✨ Key Features

<table>
<tr>
<td width="50%">

### 🎯 Quality System
- **Low**: Fast processing (~100 objects)
- **Medium**: Balanced quality (~500 objects)
- **High**: Maximum detail (~2000 objects)

</td>
<td width="50%">

### 💡 Modern UI
- Professional 2-panel layout
- Real-time preview system
- Color-coded status feedback
- Toggle-based quality selection

</td>
</tr>
</table>

## 📸 Screenshots

### Main Interface
*Professional popup with split-panel design*

### Quality Comparison
*See the difference between quality levels*

### In-Game Result
*Your pixel art directly in the level*

## 📦 Installation

### Method 1: In-Game (Recommended ⭐)
```
1. Open Geometry Dash with Geode
2. Click Geode button → Download tab
3. Search "Image Importer"
4. Click Install → Restart
```

### Method 2: Manual
```bash
1. Download .geode file from Releases
2. Place in: GeometryDash/geode/mods/
3. Restart Geometry Dash
```

### Method 3: Build from Source
```bash
git clone https://github.com/Nopro497138/Image-Importer.git
cd Image-Importer
geode build
geode package install
```

## 🎮 Quick Start Guide
```
┌─────────────────────────────────────┐
│  1. Open Editor                     │
│  2. Click "IMG" button (top-left)   │
│  3. Select your image               │
│  4. Choose quality level            │
│  5. Click "Import"                  │
│  6. Done! 🎉                        │
└─────────────────────────────────────┘
```

## 📊 Performance Guide
```ascii
Quality Levels Comparison:
    
    LOW (8x8)      MEDIUM (4x4)      HIGH (2x2)
    ┌─┬─┐          ┌──┬──┐            ┌───┬───┐
    │ │ │          │  │  │            │   │   │
    ├─┼─┤          ├──┼──┤            ├───┼───┤
    │ │ │          │  │  │            │   │   │
    └─┴─┘          └──┴──┘            └───┴───┘
   ~100 obj        ~500 obj           ~2000 obj
   ⚡ Fast         🔄 Balanced         🐌 Slow
```

## 🔧 Technical Specifications

| Feature | Details |
|---------|---------|
| **Supported Formats** | PNG, JPG, JPEG, BMP |
| **Max Resolution** | 1000x1000px (recommended) |
| **Object Type** | Square Block (ID: 1) |
| **Color Method** | RGB → ccColor3B |
| **Spawn Position** | (150, 150) |
| **Transparency** | Alpha < 50 filtered |
| **Pixel Spacing** | 1.0 unit |

## 💻 Development

### Prerequisites
- CMake 3.21+
- C++20 compiler
- Geode SDK 4.9.0+
- Git

### Building
```bash
# Setup
geode sdk install
export GEODE_SDK=~/.geode/sdk  # or set in your env

# Build
cmake -B build
cmake --build build --config Release

# Install
geode package install build/noahjo.imageimporter.geode
```

### Project Structure
```
Image-Importer/
├── src/
│   └── main.cpp          # Main mod code
├── mod.json              # Mod configuration
├── about.md              # Mod description
├── CMakeLists.txt        # Build configuration
├── README.md             # This file
└── LICENSE               # MIT License
```

## 🎨 UI Design Features

### Left Panel (Controls)
- ✨ Quality toggle buttons with visual feedback
- 📏 Image dimension display
- 🎯 Clear quality indicators

### Right Panel (Preview)
- 🖼️ Real-time image preview
- 📝 Filename display
- 🔲 Professional border design

### Status Bar
- 🟢 Green: Success
- 🟡 Yellow: Warning
- 🔴 Red: Error
- 🔵 Blue: Processing

## 📈 Roadmap

- [ ] Object grouping feature
- [ ] Custom color palettes
- [ ] Dithering algorithms
- [ ] Batch import support
- [ ] Preview grid overlay
- [ ] Export to template
- [ ] Undo functionality
- [ ] Custom spawn position

## 🐛 Known Issues

- No bulk undo for imported objects
- Objects not automatically grouped
- Fixed spawn position (150, 150)
- Large images may cause lag

## 🤝 Contributing

Contributions welcome! Please:
1. Fork the repository
2. Create feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Open Pull Request

### Code Style
- Use modern C++20 features
- Follow existing code style
- Add comments for complex logic
- Test thoroughly before submitting

## 📝 License

This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

## 🙏 Acknowledgments

- **Geode Team** - Amazing modding framework
- **GD Community** - Inspiration and feedback
- **Contributors** - Thank you for your help!

## 📞 Support

- **Issues**: [GitHub Issues](https://github.com/Nopro497138/Image-Importer/issues)
- **Discussions**: [GitHub Discussions](https://github.com/Nopro497138/Image-Importer/discussions)
- **Discord**: [Geode Discord](https://discord.gg/geode)

## ⭐ Show Your Support

If you like this mod, please consider:
- ⭐ Starring the repository
- 🐛 Reporting bugs
- 💡 Suggesting features
- 📢 Sharing with friends

---

<div align="center">

**Made with ❤️ by [Noahjo](https://github.com/Nopro497138)**

*Transform your creativity into pixel art!* 🎨✨

[⬆ Back to Top](#-image-importer-for-geometry-dash)

</div>
