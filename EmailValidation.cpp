#include <iostream>
#include <string>
using namespace std;

string validateSymbols(string email, string partName)
{
    string result;

    for (int i = 0; i < email.length() - 1; i++)
    {         
        if (!(((email[i] >= 'a') && (email[i] <= 'z')) || ((email[i] >= 'A') && (email[i] <= 'Z'))
            || (email[i] == '.') || (email[i] == '-')))
        {
            result = "Invalid. Invalid symbol founded.";
        }

        if ((i > 0) && (email[i] == '.') && (email[i - 1] == '.'))
        {
            result = "Invalid. Two dots cannot be consecutive.";
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

    for (int i = email.length() - 1; i > 0; i--)
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

    for (int i = 0; i < email.length() - 1; i++)
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

    for (int i = 0; i < email.length() - 1; i++)
    {    
        if (email[i] == '@')
        {
            dogCounter++;
        }
    }

    if ((dogCounter == 0) || (dogCounter > 1))
    {
        return result = "Invalid. Symbol '@' not found or more than 1.";
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

    result = "Valid";

    return result;
}

void correctAdressesTest()
{
    cout << endl << "Correct email adresses." << endl;
    cout << "Your email address : simple@example.com" << endl;
    cout << "Email address : " << emailValidate("simple@example.com") << endl;
    cout << "Your email address : very.common@example.com" << endl;
    cout << "Email address : " << emailValidate("very.common@example.com") << endl;
    cout << "Your email address : disposable.style.email.with+symbol@example.com" << endl;
    cout << "Email address : " << emailValidate("disposable.style.email.with+symbol@example.com") << endl;
    cout << "Your email address : other.email-with-hyphen@example.com" << endl;
    cout << "Email address : " << emailValidate("other.email-with-hyphen@example.com") << endl;
    cout << "Your email address : fully-qualified-domain@example.com" << endl;
    cout << "Email address : " << emailValidate("fully-qualified-domain@example.com") << endl;
    cout << "Your email address : user.name+tag+sorting@example.com" << endl;
    cout << "Email address : " << emailValidate("user.name+tag+sorting@example.com") << endl;
    cout << "Your email address : x@example.com" << endl;
    cout << "Email address : " << emailValidate("x@example.com") << endl;
    cout << "Your email address : example-indeed@strange-example.com" << endl;
    cout << "Email address : " << emailValidate("example-indeed@strange-example.com") << endl;
    cout << "Your email address : admin@mailserver1" << endl;
    cout << "Email address : " << emailValidate("admin@mailserver1") << endl;
    cout << "Your email address : example@s.example" << endl;
    cout << "Email address : " << emailValidate("example@s.example") << endl;
    cout << "Your email address : mailhost!username@example.org" << endl;
    cout << "Email address : " << emailValidate("mailhost!username@example.org") << endl;
    cout << "Your email address : user%example.com@example.org" << endl;
    cout << "Email address : " << emailValidate("user%example.com@example.org") << endl;
}

void incorrectAdressesTest()
{
    cout << endl << "Incorrect email adresses." << endl;
    cout << "Your email address : John..Doe@example.com" << endl;
    cout << "Email address : " << emailValidate("John..Doe@example.com") << endl;
    cout << "Your email address : Abc.example.com" << endl;
    cout << "Email address : " << emailValidate("Abc.example.com") << endl;
    cout << "Your email address : A@b@c@example.com" << endl;
    cout << "Email address : " << emailValidate("A@b@c@example.com") << endl;
    cout << "Your email address : a\"b(c)d, e:f; g<h>i[j\k]l@example.com" << endl;
    cout << "Email address : " << emailValidate("a\"b(c)d, e:f; g<h>i[j\k]l@example.com") << endl;
    cout << "Your email address : 1234567890123456789012345678901234567890123456789012345678901234+x@example.com" << endl;
    cout << "Email address : " << emailValidate("1234567890123456789012345678901234567890123456789012345678901234+x@example.com") << endl;
    cout << "Your email address : i_like_underscore@but_its_not_allow_in _this_part.example.com" << endl;
    cout << "Email address : " << emailValidate("i_like_underscore@but_its_not_allow_in _this_part.example.com") << endl;
    
}

int main()
{
    string email;

    correctAdressesTest();
    incorrectAdressesTest();

    cout << endl << "Enter your email address" << endl;
    getline(cin, email);

    cout << "Email address : " << emailValidate(email) << endl;

    return 0;
}
