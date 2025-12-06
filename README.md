# 🎨 Image Importer

**Transform images into pixel art with a professional, modern interface!**

## ✨ Features

- 🖼️ **Multi-Format Support**: PNG, JPG, JPEG, BMP
- 🎯 **Three Quality Levels**: Low, Medium, High with visual toggles
- 👁️ **Real-Time Preview**: See your image before importing
- 📊 **Live Statistics**: Image dimensions and object count estimates
- 🎨 **Accurate Colors**: True RGB to GD conversion
- 💡 **Modern UI**: Professional 2-panel interface with status feedback
- ⚡ **Smart Processing**: Automatic transparent pixel filtering

## 🎮 How to Use

### Quick Start
1. Open the Level Editor
2. Click the **"IMG"** button (circular, top-left area)
3. The Image Importer popup opens

### Import Process
1. **Select Image**
   - Click "Select Image" button
   - Browse for your file (PNG, JPG, JPEG, BMP)
   - Preview appears instantly on the right panel

2. **Choose Quality**
   - **Low**: Fast, ~100 objects (8x8 sampling)
   - **Medium**: Balanced, ~500 objects (4x4 sampling) ⭐ **Recommended**
   - **High**: Detailed, ~2000 objects (2x2 sampling)

3. **Import**
   - Click the big "Import" button
   - Wait for processing (shown in status bar)
   - Done! Your pixel art appears at position (150, 150)

## 💡 Tips & Best Practices

### For Best Results
- ✅ Start with **Medium quality** for testing
- ✅ Use images under 500x500 pixels
- ✅ High contrast images work best
- ✅ Save your level before importing
- ✅ Clear, colorful images convert better

### Performance Guide
```
Image Size    | Low Detail | Medium Detail | High Detail
------------- | ---------- | ------------- | -----------
< 200x200     | ⚡ Fast    | ⚡ Fast       | 🔄 OK
200-500px     | ⚡ Fast    | 🔄 OK         | 🐌 Slow
500-1000px    | 🔄 OK      | 🐌 Slow       | ❌ Laggy
> 1000px      | 🐌 Slow    | ❌ Laggy      | ❌ Avoid
```

### Quality Comparison

| Setting | Sampling | Approximate Objects | Speed | Best Use Case |
|---------|----------|---------------------|-------|---------------|
| **Low** | 8x8 pixels | ~100 per 100x100px | ⚡ Instant | Large backgrounds, testing |
| **Medium** | 4x4 pixels | ~500 per 100x100px | 🔄 Fast | Most images, general use |
| **High** | 2x2 pixels | ~2000 per 100x100px | 🐌 Slow | Small icons, fine details |

## 🎯 Technical Information

### Specifications
- **Object Type**: Square blocks (ID: 1)
- **Color System**: Direct RGB → ccColor3B
- **Pixel Spacing**: 1.0 units
- **Spawn Position**: (150, 150)
- **Alpha Threshold**: < 50 = transparent
- **Maximum Size**: 1000x1000px (recommended)

### File Format Support
- ✅ **PNG**: Full support, best for transparency
- ✅ **JPG/JPEG**: Full support, no transparency
- ✅ **BMP**: Full support, limited transparency

## 🚀 Performance Optimization

### Before Importing
1. Save your level as backup
2. Close other resource-intensive mods
3. Test with Low quality first
4. Check image dimensions in preview

### During Import
- Status bar shows real-time progress
- Green = Success
- Orange = Warning
- Red = Error
- Blue = Processing

### After Import
- Objects spawn at (150, 150)
- Use Select All to move the entire image
- Group objects for easier manipulation
- Save immediately to prevent loss

## ⚠️ Known Limitations

- ⚠️ **No Undo**: Imported objects can't be bulk undone
- ⚠️ **No Auto-Group**: Objects are created individually
- ⚠️ **Fixed Position**: Always spawns at (150, 150)
- ⚠️ **Performance**: Very large imports may cause lag
- ⚠️ **One-Way**: Can't export back to image

## 📐 UI Features

### Left Panel (Controls)
- Quality toggle buttons
- Visual selection feedback
- Info display with image dimensions
- Clear status messages

### Right Panel (Preview)
- Real-time image preview
- Image filename display
- Preview border for clarity
- Automatic scaling to fit

### Bottom Bar (Status)
- Color-coded status messages
- Real-time feedback
- Import progress indication
- Error/success notifications

## 🐛 Troubleshooting

**"Image not loaded"**
```
✓ Check file format (PNG, JPG, JPEG, BMP)
✓ Ensure file isn't corrupted
✓ Try a smaller file size
✓ Check file path has no special characters
```

**"Editor not found"**
```
✓ Make sure you're in the level editor
✓ Try reopening the level
✓ Restart Geometry Dash
```

**Performance Issues**
```
✓ Use Lower quality setting
✓ Reduce image size before importing
✓ Close other mods temporarily
✓ Save and restart editor
```

**Button Not Visible**
```
✓ Check if mod is enabled in Geode
✓ Look for circular "IMG" button top-left
✓ Try reloading the editor
✓ Check for conflicting mods
```

## 🎨 Design Philosophy

This mod prioritizes:
- **Clarity**: Every action has clear feedback
- **Efficiency**: Minimal clicks to complete task
- **Safety**: Status indicators prevent mistakes
- **Aesthetics**: Modern, clean interface design
- **Usability**: Intuitive workflow for all users

## 🆕 What's New in v1.0.0

- ✨ Complete UI redesign with 2-panel layout
- 🎯 Toggle buttons for quality selection
- 📊 Real-time image dimension display
- 🎨 Color-coded status feedback system
- 💡 Professional, modern interface
- ⚡ Optimized performance
- 🖼️ Enhanced preview system
- 📈 Improved error handling

## 🤝 Support

**Found a bug or have a suggestion?**
- 🐛 [Report Issues](https://github.com/Nopro497138/Image-Importer/issues)
- 💬 [Discussions](https://github.com/Nopro497138/Image-Importer/discussions)
- ⭐ [Star on GitHub](https://github.com/Nopro497138/Image-Importer)

## 📜 Credits

- **Developer**: Noahjo
- **Framework**: Geode SDK
- **UI Design**: Custom modern interface
- **Community**: GD Modding Community

---

**Made with ❤️ for the Geometry Dash community**

*Transform your creativity into pixel art!* 🎨✨
