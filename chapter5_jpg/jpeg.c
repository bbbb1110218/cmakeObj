#include <stdio.h>
#include <jpeglib.h>

int main(int argc,char *argv[]) {
    if(argc !=2){
        printf("Usage:%s photo_path\n",argv[0]);
        printf("使用方法:%s jpg图片地址\n",argv[0]);
        return -1;
    }
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    // 初始化JPEG解压对象
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    // 打开JPEG文件
    FILE *infile = fopen(argv[1], "rb");
    if (!infile) {
        fprintf(stderr, "无法打开JPEG文件\n");
        return 1;
    }

    // 将文件描述符传递给libjpeg
    jpeg_stdio_src(&cinfo, infile);

    // 读取JPEG文件的头部信息
    jpeg_read_header(&cinfo, TRUE);

    // 输出一些文件信息
    printf("图像宽度：%d\n", cinfo.image_width);
    printf("图像高度：%d\n", cinfo.image_height);
    printf("颜色空间：%d\n", cinfo.jpeg_color_space);

    // 清理并关闭文件
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);

    return 0;
}

