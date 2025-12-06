# Image Importer for Geometry Dash

A Geode mod that allows you to import images into Geometry Dash levels as pixel art!

## Features

- 🖼️ Import PNG, JPG, JPEG, and BMP images
- 🎨 Automatic color conversion to GD objects
- ⚡ Three quality levels (Low/Medium/High)
- 👁️ Live image preview
- 🎯 Smart transparent pixel handling

## Installation

### Method 1: In-Game (Recommended)
1. Open Geometry Dash with Geode installed
2. Go to the Geode menu
3. Search for "Image Importer"
4. Click Install

### Method 2: Manual Installation
1. Download the latest `.geode` file from [Releases](https://github.com/Nopro497138/Image-Importer/releases)
2. Place it in your `GeometryDash/geode/mods/` folder
3. Restart Geometry Dash

## Usage

1. Open the level editor
2. Look for the **"IMG"** button on the left side
3. Click it to open the Image Importer
4. Select your image file
5. Choose detail level:
   - **Low**: Fast, fewer objects (8x8 sampling)
   - **Medium**: Balanced (4x4 sampling)
   - **High**: Detailed, more objects (2x2 sampling)
6. Click **"Import"**

## Building from Source

### Prerequisites
- CMake 3.21+
- C++20 compiler
- Geode SDK

### Build Steps
```bash
# Clone the repository
git clone https://github.com/Nopro497138/Image-Importer.git
cd Image-Importer

# Build with Geode CLI
geode build

# Install to Geometry Dash
geode package install
```

## Tips

- Start with **Low detail** for large images to test
- Images spawn at position **(100, 100)** in the level
- Transparent pixels are automatically skipped
- High detail works best with images under 200x200 pixels

## Performance

| Detail Level | Sampling Rate | Best For |
|--------------|---------------|----------|
| Low | 8x8 | Large images (500x500+) |
| Medium | 4x4 | Normal images (200-500px) |
| High | 2x2 | Small images (<200px) |

## Known Limitations

- Very large images with High detail may cause lag
- Objects are created as simple colored squares (ID: 1)
- Maximum recommended image size: 1000x1000 pixels

## License

This project is licensed under the MIT License.

## Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest features
- Submit pull requests

## Support

Having issues? [Open an issue](https://github.com/Nopro497138/Image-Importer/issues) on GitHub!

---

Made with ❤️ for the Geometry Dash community
