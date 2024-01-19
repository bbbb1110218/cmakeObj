## curl 获取标准输出
在CURL中，如果你不希望将响应数据直接输出到标准输出，你可以使用`CURLOPT_WRITEFUNCTION`和`CURLOPT_WRITEDATA`选项。首先，你需要创建一个函数来处理数据，然后将这个函数和一个缓冲区传递给CURL。

以下是一个示例：

```c
struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if(ptr == NULL) {
    /* out of memory! */ 
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

// 在你的CURL代码中
CURL *curl_handle;
CURLcode res;

struct MemoryStruct chunk;

chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */ 
chunk.size = 0;    /* no data at this point */ 

curl_global_init(CURL_GLOBAL_ALL);

/* init the curl session */ 
curl_handle = curl_easy_init();

/* specify URL to get */ 
curl_easy_setopt(curl_handle, CURLOPT_URL, "http://www.example.com");

/* send all data to this function  */ 
curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

/* we pass our 'chunk' struct to the callback function */ 
curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

/* get it! */ 
res = curl_easy_perform(curl_handle);

/* check for errors */ 
if(res != CURLE_OK) {
  fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
}
else {
  /*
   * Now, our chunk.memory points to a memory block that is chunk.size
   * bytes big and contains the remote file.
   *
   * Do something nice with it!
   */ 

  printf("%lu bytes retrieved\n", (long)chunk.size);
}

/* cleanup curl stuff */ 
curl_easy_cleanup(curl_handle);

free(chunk.memory);

/* we're done with libcurl, so clean it up */ 
curl_global_cleanup();
```

这段代码将把从URL获取的所有数据存储在`chunk.memory`中，而不是直接输出到标准输出。