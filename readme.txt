*****
*****

// Folders named "fonts" and "pic"  contain the necessary resources for the game. These folders should be in the same directory with the exe.

*****
*****

All source code can be used without Microsoft Visual Studio project. They are in the folder named SourceCode in the "Project" folder.

*****
*****

// Necessary Libraries:

1- SFML 2.3 
http://www.sfml-dev.org/download/sfml/2.3/

2- Bullet Physics SDK 2.83.7
https://github.com/bulletphysics/bullet3/tree/2.83.7
https://codeload.github.com/bulletphysics/bullet3/zip/2.83.7

*****
*****

// Preprocessor Definitions:

SFML_STATIC

*****
*****

// Linker dependencies:

BulletDynamics_vs2010.lib;BulletCollision_vs2010.lib;LinearMath_vs2010.lib;winmm.lib;gdi32.lib;opengl32.lib;freetype.lib;jpeg.lib;sfml-graphics-s.lib;sfml-system-s.lib;sfml-window-s.lib;sfml-audio-s.lib;kernel32.lib;user32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;

*****
*****