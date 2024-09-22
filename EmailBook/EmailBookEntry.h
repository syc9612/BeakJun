#include <string>
#include <assert.h>

class EmailBookEntry
{
public:
    static create(std::string name, std::string email);
    bool is_valid();
private:
    EmailBookEntry(std::string name, std::string email);
    static latest_index_;
    int index_;
    std::string name_;
    std::string email_;
};

// auto entry = EmailBookEntry.create("syc", "syc@naver.com");

class EmailBook
{
public:

    const EmailBook& findByIndex(int index);
    std::vector<EmailBook> findByName(std::string const& name);
    bool createEntry(std::string const& name, std::string const& email);
    const EmailBook& deleteByIndex(int index);
    const EmailBook& update(int index, ...);

    void save(어디에)
    void load(어디서)

private:
    std::vector<int, EmailBookEntry> books_;
};

bool EmailBook::createEntry(std::string const& name, std::string const& email)
{
    auto entry = EmailBookEntry::create(name, email);
    books_.push_back(entry);

}