[![Build Status](https://travis-ci.org/smartdu/kafkaclient-cpp.svg?branch=master)](https://travis-ci.org/smartdu/kafkaclient-cpp)
# kafkaclient-cpp
与[Kafka](https://kafka.apache.org/)配套的c++客户端，实现Consumer和Producer，项目来源于[librdkafka](https://github.com/edenhill/librdkafka)，它是一个优秀的开源项目，我们在使用它的时候遇到一些小问题（死循环，消费数据慢，一些内存assert），在尝试阅读源码时，无法领会它的设计思想，同时在代码里用了引用计数器来释放内存，多个数据队列拷贝数据，理不清思路，尝试多次无果，所以才有这个项目的诞生，也方便自己理解Kafka设计思想。

该项目参考Kafka的源码，比如协议解析等，抽象出Type，Field，Schema，在协议扩展，以及阅读源码上有很清晰的全局观。

测试使用的kafka版本是[kafka_2.12-2.2.0](http://mirror-hk.koddos.net/apache/kafka/2.2.0/kafka_2.12-2.2.0.tgz)

# 开发原则 #
  * 单线程
  * 接口傻瓜
  * 模块化开发
  * 跨平台
  * 高性能

# 编译方式
## Linux
执行[build.sh](./build.sh)会在`.libs`下生成`include`，`lib`目录
## Windows
用VS2017打开[kafkaclient-cpp.sln](./kafkaclient-cpp.sln)，`Platform Toolset`使用`Visual Studio 2012 (v110)`

# 遗留问题
  * 内存管理（代码里到处是new，没有delete，后续使用智能指针）

# 开发计划
  * ~~理清[Kafka协议](https://kafka.apache.org/protocol)，如何扩展协议版本，以及解析~~
  * ~~参考Kafka的源码，尝试用C++方式重写~~
  * ~~完成第一个协议解析[ApiVersions](https://kafka.apache.org/protocol#The_Messages_ApiVersions)~~
  * 用Wireshark抓Consumer的交互报文，实现其他协议解析
  * 构建一个简单的Consumer，实现单Partition的数据消费
  * 构建一个简单的Consumer，实现Group数据消费
  * ...

# 解析ApiVersions
[version.bin](test/version.bin)在test目录下，通过Wireshark抓包后转存后的二进制文件

代码如下：
``` c++
char buffer[1024];
FILE *file = fopen("version.bin", "rb");
int ret = fread(buffer, 1, sizeof(buffer), file);
fclose(file);

ByteBuffer *b = ByteBuffer::wrap(buffer + 8, ret - 8);
short version = 2;

ApiVersionsResponse *v = ApiVersionsResponse::parse(b, version);
std::list<ApiVersion> versions = v->apiVersions();
for (auto iter : versions)
{
	printf("api_key = %d, min_version = %d, max_version = %d\n", iter.apiKey, iter.minVersion, iter.maxVersion);
}
delete v;
```

输出：
<pre>
api_key = 0, min_version = 0, max_version = 7
api_key = 1, min_version = 0, max_version = 10
api_key = 2, min_version = 0, max_version = 5
api_key = 3, min_version = 0, max_version = 7
api_key = 4, min_version = 0, max_version = 2
api_key = 5, min_version = 0, max_version = 1
api_key = 6, min_version = 0, max_version = 5
api_key = 7, min_version = 0, max_version = 2
api_key = 8, min_version = 0, max_version = 6
api_key = 9, min_version = 0, max_version = 5
api_key = 10, min_version = 0, max_version = 2
api_key = 11, min_version = 0, max_version = 4
api_key = 12, min_version = 0, max_version = 2
api_key = 13, min_version = 0, max_version = 2
api_key = 14, min_version = 0, max_version = 2
api_key = 15, min_version = 0, max_version = 2
api_key = 16, min_version = 0, max_version = 2
api_key = 17, min_version = 0, max_version = 1
api_key = 18, min_version = 0, max_version = 2
api_key = 19, min_version = 0, max_version = 3
api_key = 20, min_version = 0, max_version = 3
api_key = 21, min_version = 0, max_version = 1
api_key = 22, min_version = 0, max_version = 1
api_key = 23, min_version = 0, max_version = 2
api_key = 24, min_version = 0, max_version = 1
api_key = 25, min_version = 0, max_version = 1
api_key = 26, min_version = 0, max_version = 1
api_key = 27, min_version = 0, max_version = 0
api_key = 28, min_version = 0, max_version = 2
api_key = 29, min_version = 0, max_version = 1
api_key = 30, min_version = 0, max_version = 1
api_key = 31, min_version = 0, max_version = 1
api_key = 32, min_version = 0, max_version = 2
api_key = 33, min_version = 0, max_version = 1
api_key = 34, min_version = 0, max_version = 1
api_key = 35, min_version = 0, max_version = 1
api_key = 36, min_version = 0, max_version = 1
api_key = 37, min_version = 0, max_version = 1
api_key = 38, min_version = 0, max_version = 1
api_key = 39, min_version = 0, max_version = 1
api_key = 40, min_version = 0, max_version = 1
api_key = 41, min_version = 0, max_version = 1
api_key = 42, min_version = 0, max_version = 1
api_key = 43, min_version = 0, max_version = 0
</pre>
