#include "nucleus.h"
#include "macros.h"
#include "default_console.h"
#include "c++ctors.h"

// Run static construction for kernel.
extern "C" void entry(address_t mem_end, multiboot_t::mmap_t* mmap)
{
    run_global_ctors();
    nucleus_n::nucleus.init(mem_end, mmap);
}

namespace nucleus_n
{

// Our global static kernel object.
nucleus_t nucleus;

nucleus_t::nucleus_t()
    : memory_manager()
{
    kconsole << GREEN << "Hello, nucleus!" << endl;
}

void nucleus_t::init(address_t mem_end, multiboot_t::mmap_t* mmap)
{
    memory_manager.init(mem_end, mmap);
}

void nucleus_t::enter_trap(UNUSED_ARG int portal_no)
{
}

void nucleus_t::create_pd()
{
}

void nucleus_t::destroy_pd()
{
}

}