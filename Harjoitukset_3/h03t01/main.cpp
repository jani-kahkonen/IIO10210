#include <iostream>
#include <string>

class User {
public:
	User(std::string uName, int uId) : _uName(uName), _uId(uId) {	std::cout << "User" << std::endl;	}
	User() : _uName(""), _uId(0) { std::cout << "User: " <<  _uId << std::endl;  }
protected:
	int			_uId;
	std::string	_uName;
};

class LinuxUser : public User{
public:
	void print(){	std::cout << _uId << "\n" << _uName << "\n" << _home << "\n" << _shell << "\n" << _editr << "\n";	}

	void setEditor(std::string editr) { _editr = editr; }
	void setUname(std::string uName) { _uName = uName;  }
	void setId(int uId) { _uId = uId;	 }

	LinuxUser(std::string un, int ui, std::string ho, std::string sh, std::string ed) : User(un, ui), _home(ho), _shell(sh), _editr(ed){	std::cout << "LinuxUser" << std::endl;	}
	LinuxUser() : _home(0), _shell(0), _editr(0) { std::cout << "LinuxUser: " << _uId << std::endl; }
private:
	std::string	_home,	_shell,	_editr;
};

int main() {
	LinuxUser lucky("lucky", 501, "/home/lucky", "/bin/bash", "vi");
	lucky.print();

	LinuxUser root("root", 0, "/root", "/bin/bash", "nano");
	//root.setId(1);
	//root.setEditor("emacs");
	//root.setUname("rootti");
	root.print();
}