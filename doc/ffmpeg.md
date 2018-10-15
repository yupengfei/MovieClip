# ffmpeg入门手册

## 截图

### 概述

视频文件有一些基础的组件。首先，文件本身被称为一个容器，容器的类型决定了文件里的信息的存放位置。AVI和QuickTime都是容器。接下来，我们有一些流，通常我们会有一个音频流和一个视频流。流里面的有一系列被称为帧的元素。每一个流被一种编解码器编码。编码器定义了真实的数据如何被编解码。DivX和MP3都是编码器。Packets被从流中读出，它们是一小段数据可以被解码成原始的帧，以便让应用程序进行处理。一个packet可能包含一个视频帧或者多个音频帧，也可能包含不到一个。

在最简单的层面上，处理音视频流非常简单：
```
10 打开video.avi的视频流
20 从视频流中读取packet解码到frame
30 如果当前frame不完整 GOTO 20
40 处理视频帧
50 GOTO 20
```

用ffmpeg处理视频基本上都是上述的流程，只是某些程序处理视频帧部分非常复杂。在本例子中，我们打开一个文件，读入其中的视频流，我们的处理视频帧为将帧写入到一个ppm文件。

### 打开文件

首先，我们打开一个文件。使用ffmpeg时，首先需要初始化库
```c
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <ffmpeg/swscale.h>
...
int main(int argc, charg *argv[]) {
av_register_all();
```
上述代码将所有可用的文件格式和编解码器注册，所有当我们打开文件时对应的格式和编解码器会自动的被使用。我们只需要调用av_register_all()一次，所以我们在main中调用。我们也可以只注册指定类型的文件格式和编解码器，但是一般情况下并不必要。

接下来我们打开文件

```c
AVFormatContext *pFormatCtx = NULL;

// Open video file
if(avformat_open_input(&pFormatCtx, argv[1], NULL, 0, NULL)!=0)
  return -1; // Couldn't open file
```

我们将文件名作为第一个参数，该函数读取文件的头信息并将文件格式相关的信息存储在我们传入的AVFormatContext结构体中。后面三个参数用户指定文件的格式、缓存的大小和格式的参数，通过设置为NULL或者0，libavformat将会自动检测它们。