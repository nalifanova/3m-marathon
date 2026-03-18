#ifndef INC_3M_MARATHON_WEEK1_H
#define INC_3M_MARATHON_WEEK1_H

#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"

#include <memory>
#include <cstdio>

class FileReader {
public:
    explicit FileReader(const char* path) {
        m_file = fopen(path,"r");
    }

    ~FileReader() {
        fclose(m_file);
    }

private:
    FILE* m_file;
};

class FileReaderAlt {
public:
    FileReaderAlt(const char* path)
    : m_file(fopen(path, "r"), &fclose) {}

private:
    std::unique_ptr<FILE, decltype(&fclose)> m_file;
};

class Logger {
    Logger() = default;
    ~Logger() = default;
};

class Timer {
    Timer() = default;
    ~Timer() = default;
};

#endif //INC_3M_MARATHON_WEEK1_H
