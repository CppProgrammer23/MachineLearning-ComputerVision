**Setup OpenCV on MSVC++ without CMake**

**Go to:** https://opencv.org/releases/ and select Windows.

Once the download is finished click on the setup to extract the contains (choose your folder).

Create new project with Visual Studio.

Go to properties:

**NB: forget the Source Folder** we will use only the **build** folder for all the configuration.

1/ C/C++ >> General >> Additional Include Directory: add the path where the include folder lives (build/include) 

2/a) Linker >> General >> Additional Library Directory: add the path where the lib folder lives (build/x64/vc15/lib)

  b) Input >> Additional Dependencies >> add: opencv_world440d.lib (for debug)
  
3/ Save and Ok
