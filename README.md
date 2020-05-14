### seeker logger v0.1.0
---
### 说明
seeker logger 并不是一个log库，而是一个 [spdlog](https://github.com/gabime/spdlog) 库的简单封装和用法约定，以达到使用方便和代码统一的目的；  

### 安装
- 添加h文件到你工程的include路径中
  - seeker/logger.h
  - seeker/loggerApi.h
  - spdlog

### 使用
- main函数所在文件
  - 添加 `#include "seeker/logger.h"`
  - 在main函数中，尽可能早的对logger进行初始化：`seeker::Logger::init();`
- 所有需要使用log功能的文件
  - 将 `#include "config.h"` 作为第一个引入
  - 添加 `#include "seeker/loggerApi.h"`
- 用如下写法来打印日志
```
  T_LOG("got message, type={}", msg.type );  //打印Trace级别日志，最低级别
  D_LOG("request count={}", count);  //打印Debug级别日志
  I_LOG("user[{}] login at {}", userName, time);   //打印Info级别日志
  W_LOG("Request Error: [{}] {} stateCode: {}", req.method, req.path, res.status);  //打印Warning级别日志
  E_LOG("CPU error stateCode: {}", code);  //打印Error级别日志，最高级别
```

### 修改日志文件名
- 日志文件名，默认为`application.log`
- 通过指定`LOG_FILE_NAME `宏的值，来自定义日志文件名
- 注意，定义这个宏的时候，宏的值需要有双引号，例如：`#define LOG_FILE_NAME "mylogfile.log"`

### 修改日志输出级别
- 默认的日志输出级别为 INFO
- 通过指定`SPDLOG_ACTIVE_LEVEL`宏的值，来修改日志输出级别
- `SPDLOG_ACTIVE_LEVEL`宏的有效值为：
  - `SPDLOG_LEVEL_TRACE`
  - `SPDLOG_LEVEL_DEBUG`
  - `SPDLOG_LEVEL_INFO`
  - `SPDLOG_LEVEL_WARN`
  - `SPDLOG_LEVEL_ERROR`
  - `SPDLOG_LEVEL_CRITICAL`
  - `SPDLOG_LEVEL_OFF`

### 使用CMake的config.h.in完成配置的例子
- config.h.in里添加配置
```
#cmakedefine SPDLOG_ACTIVE_LEVEL @SPDLOG_ACTIVE_LEVEL@
#cmakedefine LOG_FILE_NAME "@LOG_FILE_NAME@"
```
- CMakeLists.txt进行配置
```
set(LOG_FILE_NAME "application.log")
set(SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE)
```
这个配置要放在`configure_file(config.h.in config.h)` 之前
