#include <unistd.h>
#include <iostream>

int main() {
    while (true) {
	std::cout<<"hellow world"<<std::endl;
	usleep(100000);
    }
    return 0;
}
