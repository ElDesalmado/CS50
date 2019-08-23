/*Harvard CS50:01-Mario.
This program builds a pyramid of '#' blocks.*/

#include <iostream>
#include <string>

const char block = '#',
air = ' ';

std::string CreatePyramid(size_t height);
void MsgInvalidInput();

int main()
{
    // default height
    size_t heightInput = 6,
        counterInput = 5,
        counterWarnings = 0;

    std::string warnings[] = 
    { 
        { "The pyramid you are asking to build would be too high!" },
        { "Mario would not be happy about this..." },
        { "Do you have any relatives from Egypt?" },
        { "Ok. You've asked for this..." } 
    };

    while (counterInput)
    {
        std::string input;
        std::cout << "To build a pyramid, enter Height (one integer value: 0 < value <= 100):\n->";
        std::getline(std::cin, input);

        //try to convert user input to int
        try
        {
            int height = std::stoi(input);
            if (height > 0 &&
                height <= 100)
            {
                heightInput = (size_t)height;
                break;
            }
            else if (height > 100)
            {
                std::cout << warnings[counterWarnings++] << std::endl;
                if (counterWarnings > 3)
                {
                    heightInput = (size_t)height;
                    break;
                }
                continue;
            }
            MsgInvalidInput();
        }
        catch (std::invalid_argument arg)
        {
            MsgInvalidInput();
        }
        catch (std::out_of_range)
        {
            std::cout << "Entered value is out of range." << std::endl;
        }

        // reset warnings, input must exceed 100 for 3 times in a row
        counterWarnings = 0;
        --counterInput;
    }
    if (!counterInput)
        std::cout << "I'm tired of you, Dummy! Here's the Default pyramid!" << std::endl;

    std::cout << CreatePyramid(heightInput);

    return 0;
}

std::string CreatePyramid(size_t height)
{
    std::string out;
    size_t airDistance = height;
    while (airDistance--)
        out += std::string(airDistance, air) + std::string(height - airDistance, block) + '\n';

    return out;
}

void MsgInvalidInput()
{
    std::cout << "You must enter one integer value not less or equal zero." << std::endl;
}
