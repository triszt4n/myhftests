/**
 * @file profile.h
 * @brief Profile abstract class declaration
 */

#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <iostream>
#include <ctime>

/**
 * @enum Rights
 * @brief Enumerator for verifyLogin to return the result of found profile
 */
enum Rights {
    DEFAULT,
    DELIVERER,
    ADMIN,
    NOT_MATCHING
};

/**
 * @class Profile
 * @brief Abstract parent class for profiles
 */
class Profile {
protected:
    std::string username;
    std::string password;
    std::string name;
    time_t regDate; ///< Will be assigned automatically upon creation
public:
    Profile(const std::string& username, const std::string& pw = "", const std::string& name = ""):
        username(username), password(pw), name(name)
    {
        regDate = std::time(0);
    }

    std::string getUsername() const;
    std::string getName() const;
    bool operator==(const Profile& rhs) const;
    virtual Rights verifyLogin(const std::string& username, const std::string& pw) const = 0;
    virtual void greetings(std::ostream& os) const = 0;
    virtual void save(std::ostream& os) const = 0;
    virtual void load(std::istream& is) = 0;
    virtual Profile* clone() const = 0;
    virtual ~Profile() { }
};

#endif // PROFILE_H
