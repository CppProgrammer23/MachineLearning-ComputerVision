**Tensorflow configuration on MSVC++**

**Go to:**
https://www.tensorflow.org/install/lang_c

download (Windows CPU only or Windows GPU only or both; depending on your need). extract the folder in your choosen folder (libtensorflow windows x86-64 cpu for CPU 
or libtensorflow windows x86-64 gpu for GPU).

**Include and linker:**

Go to properties:

1/ C/C++ >> General >> Additional Include Directory: add the path where the include folder lives. (it's in the folder libtensorflow windows x86-64 cpu 
or libtensorflow windows x86-64 gpu)

2/ a) Linker >> General >> Additional Library Directory: add the path where the lib folder lives

   b) Input >> Additional Dependencies >> add: tensorflow.lib

3/ save and ok.

4/ Copy the tensorflow.dll file into your project folder where main.cpp lives.

Now you can test this for the CPU and GPU configuration (TF version):

```
#include <iostream>
#include "tensorflow/c/c_api.h"

int main()
{
	std::cout << TF_Version();
	return 0;
}
```

Now for the GPU, some GPU settings are needed otherwise you will get this message on the console:
```
2020-10-22 17:05:08.450662: W tensorflow/stream_executor/platform/default/dso_loader.cc:59] Could not load dynamic library 'cudart64_101.dll'; dlerror: cudart64_101.dll not found
2020-10-22 17:05:08.457352: I tensorflow/stream_executor/cuda/cudart_stub.cc:29] Ignore above cudart dlerror if you do not have a GPU set up on your machine.
```
