# 模仿malloc 函数
只能在linux系统上工作，macos没用
todo 未完成

```c
typedef long Align;
union header {
	struct {
		union header *ptr; //指针
		unsigned size;
	} s;
	Align x;
};

typedef union header Header;

static Header base;
static Header *freeptr = NULL;
```
base 是基地址
freeptr 应该是下一个的指针
