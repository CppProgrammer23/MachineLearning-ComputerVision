**Tensorflow configuration on MSVC++**

**Go to:**
https://www.tensorflow.org/install/lang_c

download (Windows CPU only or Windows GPU only or both; depending on your need). extract the folder in your choosen folder (libtensorflow windows x86-64 cpu for CPU 
or libtensorflow windows x86-64 gpu for GPU).

**Include and linker:**

Go to properties:

1/ C/C++ >> General >> Additional Include Directory: add the path where the include folder lives. (it's in the folder libtensorflow windows x86-64 cpu 
or libtensorflow windows x86-64 gpu)

2/ a) Linker >> General >> Additional Library Directory: add the path where the lib folder lives.
   b) Input >> Additional Dependencies >> add: tensorflow.lib

3/ save and ok.

4/ Copy the tensorflow.dll file into your project folder where main.cpp lives.

Now for the GPU, some GPU settings are needed
