# vtfconvert
A program to transform images to VTF files and vice versa.

Originally written to ease the process of making custom textures for
Valve Software's Counter-Strike: Global Offensive (CSGO)
but has applications for other Valve games.

#### Usage:
```bash
  vtfconvert <input file> <output file>
```

The program identifies files primarily by extension. If input file is not a VTF file,
the output file will explicitly be rendered as a VTF file regardless of the file extension.

If the input file is a VTF file the conversion is determined by the output file's extension.

#### Dependencies:
DEveloper's Imaging Library (DEVIL) aka [OpenIL](http://openil.sourceforge.net/)
