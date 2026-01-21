# Voxel Engine Workshop
This repository contains a suite of small exercices of increasing difficulty which aims to help you learn the basics of OpenGL C API with our dear friend C++. Altough all of the projects uses C++, it's mostly C with a bit of classes to organise the code. So if you never touched C++ but you know your C a bit, everything should be fine ! And in the case you don't know C yet, well, idk...

You can do the exercices in any order as the result of each one is used in the next one.

If you feel stuck or don't understand things, most of these exercices are based on the progression of the [learnopengl.com](https://learnopengl.com) website. You will find more detailed tutorials in here with code to copy & paste while reading mouthfuls of interesting technical blablabla.

Finally, just take your time, have fun ! Go wild !

# Primer on Cmake & C++

For those of who never have touched these yet, don't worry we will only use C++ for organizing code & CMake for compiling (everything CMake related is already ready).

## CMake

First, make sure you have CMake and Ninja on your machine. If not, you can install them using your favorite package manager. Here are the commands for some popular Linux distributions:

### Ubuntu/Debian based
```bash
sudo apt update
sudo apt install cmake ninja-build
```

### Fedora
```bash
sudo dnf install cmake ninja-build
```

### Arch Linux
```bash
sudo pacman -S cmake ninja
```

### openSUSE
```bash
sudo zypper install cmake ninja
```

### CentOS/RHEL
```bash
sudo yum install cmake ninja-build
```

If your distribution is not listed here, refer to its documentation for the appropriate package manager commands.

```Bash
# First generate the build files based on the local CMakeLists.txt file into a folder named build
mkdir build
cmake -S ./ -B ./build/

# Run the build system (Make in our case)
cmake --build build # With `build` being the folder you choose last step
```

You will need to run these 3 commands for each exercices, if you want to skip the hassle, just write a little script <3

## C++

### Classes

You can see them as structures with functions in it.
```cpp
class Player {

 public:  // Everything in public is accessible to functions external to the class

    // Constructor, called when the class is instanciated
    Player(const char &name) // Name is passed as reference, it's a pointer that can't be null but with the same synthax as if it was a simple var
        : m_name(new char[std::strlen(&name) + 1]) // You can attribute member variables values here (even consts ones)
        // new replaces malloc
    {
        if (m_name == void) {
            std::printf("ERROR: Could not allocate memory for the name of the Player %s\n", name);
            exit 84;
        }
        m_health_point = 100;
        m_damage = 32;
    }


    ~Player() // Destructor, called when the class goes out of scope
    {
        delete m_name; // delete replaces free
    }


    void take_damage(int damage) {
        if (damage > m_health_point) {
            m_health_point = 0;
        } else {
            m_health_point -= damage;
        }
    }


 // The const at the end means the fonction does not modifies any of the variables in the class
    std::uint8_t get_damage() const {
        return m_damage;
    }

 private: // Only functions of this class can access these variables

    const char *m_name;
    std::uint8_t m_health_point;
    std::uint8_t m_damage;
    // The synthax `::` is called namespaces, it can be interpreted as modules, a way to sort your code and avoid name collisions.
    // std::uint8_t is a type of size (1 byte == unsigned char) under the std (standard library) namespace
};
```

Then in usage this class will give something like this:

```cpp
// constexpr is the same as const, only that it is initialized as compile time (like MACROS but cleaner)
constexpr std::string k_good_guy_name = "Joseph";
constexpr std::string k_bad_guy_name = "Dio";

int main(void) {
    Player human(k_good_guy_name);
    Player vampire(k_bad_guy_name);// Here I create 2 players with the constructor I defined earlier

    humain.take_damage(vampire.get_damage()); // Both of them attack each-others
    vampire.take_damage(humain.get_damage()); // Both of them attack each-others

    return;
}
```

And here you go !

I know it might be a bit overwhelming but again, by using it progressively trough the code of the project, you will manage to at least use it (that not that important if you don't understand all of the inside out, TEK 2's here for this)

# External resources

### [learnopengl.com](https://learnopengl.com)

Best source available for free on the internet, more than decade old but still incredibly usefull.
