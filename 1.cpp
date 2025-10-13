#include <iostream>
#include <fstream> // 用于文件流操作的库

// #include "your_header_file.h" // 如果你把上面的结构体放在一个头文件里，就包含它

// ... 在这里定义 WavHeader 结构体 ...

// 把这个结构体定义放在 main 函数的外面
#include <cstdint> // 引入这个头文件以使用 uint32_t, uint16_t 等精确长度的整数

#pragma pack(push, 1) // 你发明的“反优化”指令，确保结构体紧凑
struct WavHeader {
    char     riff_id[4];      // "RIFF" 标识，由4个字符组成
    uint32_t file_size;       // 4字节长度的数字
    char     wave_id[4];      // "WAVE" 标识
    char     fmt_id[4];       // "fmt " 标识
    uint32_t fmt_size;        // 4字节数字
    uint16_t audio_format;    // 2字节数字
    uint16_t num_channels;    // 2字节数字
    uint32_t sample_rate;     // 4字节数字
    uint32_t byte_rate;       // 4字节数字
    uint16_t block_align;     // 2字节数字
    uint16_t bits_per_sample; // 2字节数字
    char     data_id[4];      // "data" 标识
    uint32_t data_size;       // 4字节数字
};
#pragma pack(pop) // 恢复编译器默认的对齐方式


int main(int argc, char* argv[]) {
    // 步骤0: 检查用户是否在命令行上提供了一个文件名。
    if(argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <wav file>" << std::endl;
        return 1; // 非零返回值通常表示错误
    }
    // 步骤1: 创建一个我们的 WavHeader 结构体实例。它一开始是空的。
    WavHeader myHeader;

    // 步骤2: 创建一个输入文件流(input file stream)对象。这就是我们通往文件的“房卡”。
    //         可以把它想象成 cin 的文件版本。
    std::ifstream file_stream;

    // 步骤3: 打开用户提供的文件。至关重要的一点：必须以二进制(binary)模式打开。
    //         语法大概是这样: file_stream.open("文件名", std::ios::binary);
    file_stream.open(argv[1], std::ios::binary);

    // 步骤4: 检查文件是否成功打开。如果失败，打印错误信息并退出程序。
    if(!file_stream.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1; // 非零返回值通常表示错误
    }

    // 步骤5: 这是最神奇的一步。使用文件流的 .read() 方法来填充你的结构体。
    //         它需要知道要把数据放到哪里 (&myHeader)，以及要读取多少数据 (sizeof(myHeader))。
    //         这里你需要用到一个 `reinterpret_cast`，因为 .read() 是按原始字符来工作的。
    file_stream.read(reinterpret_cast<char*>(&myHeader), sizeof(myHeader));

    // 步骤6: 关闭文件，释放系统资源。
    file_stream.close();
    // 步骤7: 打印你的结构体中的一些值（例如 myHeader.sample_rate），看看是否成功了。
    std::cout << "Sample Rate: " << myHeader.sample_rate << std::endl;
    std::cout << "Bits Per Sample: " << myHeader.bits_per_sample << std::endl;
    std::cout << "Number of Channels: " << myHeader.num_channels << std::endl;      
    return 0;   
}