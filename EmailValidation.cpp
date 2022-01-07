#include <iostream>
#include <string>
using namespace std;

string validateSymbols(string email, string partName)
{
    string result;

    for (int i = 0; i < email.length(); i++)
    {         
        if (!(((email[i] >= 'a') && (email[i] <= 'z')) || ((email[i] >= 'A') && (email[i] <= 'Z'))
            || (email[i] == '.') || (email[i] == '-')))
        {
            result = "Invalid. Invalid symbol founded.";
        }

        if (partName == "first")
        {
            if ((email[i] == '!') || (email[i] == '#') || (email[i] == '$') || (email[i] == '%') || (email[i] == '&')
                || (email[i] == '\'') || (email[i] == '*') || (email[i] == '+') || (email[i] == '-') || (email[i] == '/')
                || (email[i] == '=') || (email[i] == '?') || (email[i] == '^') || (email[i] == '_') || (email[i] == '`')
                || (email[i] == '{') || (email[i] == '|') || (email[i] == '}') || (email[i] == '~'))
            {
                result = "Valid";
            }

            if ((i == 0) && (email[i] == '.'))
            {
                return "Invalid. Symbol '.' in the end of first part.";
            }
        }
        else if (partName == "second")
        {
            if ((i == email.length() - 1) && (email[i] == '.'))
            {
                return "Invalid. Symbol '.' in the end of second part.";
            }
        }        
    }

    return result;
}

string secondPartValidate(string email)
{
    string part2;

    for (int i = email.length(); i > 0; i--)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
        {
            part2 = email[i] + part2;
        }
    }

    if ((part2.length() > 63) || (part2.length() < 1))
        return "Invalid. Length of second part more then 63 or less then 1";

    return validateSymbols(part2, "second");
}

string firstPartValidate(string email)
{
    string part1;

    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
        {
            part1 += email[i];
        }
    }

    if ((part1.length() > 64) || (part1.length() < 1))
        return "Invalid. Length of first part more then 64 or less then 1";

    return validateSymbols(part1, "first");
}

string emailValidate(string email)
{
    string result;
    int dogCounter = 0;

    for (int i = 0; i < email.length(); i++)
    {    
        if (email[i] == '@')
        {
            dogCounter++;
        }
    }

    if ((dogCounter == 0) || (dogCounter > 1))
    {
        result = "Invalid. Symbol '@' not found or more than 1.";
    }
    else
    {
        result = firstPartValidate(email);

        if (result[0] == 'I')
            return result;

        result = secondPartValidate(email);

        if (result[0] == 'I')
            return result;
    }

    return result;
}

int main()
{
    string email;

    cout << "Enter your email address" << endl;
    getline(cin, email);

    cout << "Email address : " << emailValidate(email) << endl;

    return 0;
}
