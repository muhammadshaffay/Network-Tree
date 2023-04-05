#include <iostream>
using namespace std;

// class having device's attributes
class TreeNode
{
	string device;
	string IP_adress;

public:
	TreeNode* right;
	TreeNode* left;

	TreeNode()
	{
		device = IP_adress = " ";
		left = right = NULL;
	}
	TreeNode(string d, string ip)
	{
		device = d;
		IP_adress = ip;
		left = right = NULL;
	}

	void setdevice(string d)
	{	device = d;	}

	string getdevice()
	{	return device;	}

	void setip(string ip)
	{	IP_adress = ip;	}

	string getip()
	{	return IP_adress;	}

	TreeNode* getRight()
	{	return right;	}

	void setLeft(TreeNode* l)
	{	left = l;	}

	TreeNode* getLeft()
	{	return left;	}

	void setRight(TreeNode* r)
	{	right = r;	}
};

//main controlling class
class BST
{
	TreeNode* root;

public:
//default constructor
	BST()
	{	root = NULL;	}

//parameterized constructor
	BST(TreeNode* r)
	{	root = r;	}

//getter setters for root
	void setroot(TreeNode* r)
	{	root = r;	}

	TreeNode* getroot()
	{	return root;	}

//Inserting networks and servers
	void insertion(TreeNode*& roote, string d, string ip)
	{
		if (roote == NULL)
		{
			TreeNode* temp = new TreeNode(d, ip);
			roote = temp;
		}
		if (roote->getip() > ip)
		{
			insertion(roote->left, d, ip);
		}
		else if (roote->getip() < ip)
		{
			insertion(roote->right, d, ip);
		}
	}

	void insert(string d, string ip)
	{
		insertion(root, d, ip);
	}

//Assigning Laptop as Root
	void specials(string l, string ip, TreeNode*& roote)
	{
		TreeNode* temp = new TreeNode(l, ip);
		temp->left = roote;
		temp->right = NULL;

		roote = temp;
	}
	void special(string l, string ip)
	{
		specials(l, ip, root);
	}

// Displaying Server Paths
	void displays(TreeNode* roote, string ip)
	{
		if (roote == NULL)
		{	return;	}

		if (ip < roote->getip())
			displays(roote->left, ip);

		else if (ip > roote->getip())
			displays(roote->right, ip);
			
		cout << roote->getdevice() << " <- ";
		return;
	}
	void display(string ip)
	{
		displays(root->left, ip);
		cout << "Laptop";
	}
};

int main()
{
	string laptop = "Laptop";
	string ip = "192.168.11.29";

//string arrays containing Ips and device names	
	string device[18] = { "Router" , "L2" , "L4" , "TikTok Server"  , "L3"  , "L5"  , "Daraz Server"  , "L6"  , " L8"  , "PakWheels Server"  , "L7"  , "AliExpress Server"  , " L1"   , "L13"   , "Netflix Server"   , " L12"   , "Torrent Server"   , "Google Server" };
	string IP_adress[18] = { "192.168.11.01" , "172.132.11.01" , "172.129.11.03 " , "172.129.11.08 " , "172.150.11.01" , "172.150.09.01" , "172.150.08.01" , "172.150.13.01" , "172.150.12.08" , "172.150.12.03" , "172.150.13.32" , "172.150.13.40" , "192.176.11.01" , "192.170.11.08" , "192.170.11.03" , "192.180.11.10" , "192.180.11.13" , "192.180.11.09" , };

	BST object;

//inserting router , networks and servers
	for (int i = 0; i < 18; i++)
	{	object.insert(device[i], IP_adress[i]);	}

//assigning laptop to root
	object.special(laptop, ip);
	
//sending 8 server IPs for displaying path from Laptop

	object.display("172.129.11.08");
	cout<<endl;cout<<endl;
	object.display("172.150.08.01");
	cout<<endl;cout<<endl;
	object.display("172.150.12.03");
	cout<<endl;cout<<endl;
	object.display("172.150.13.40");
	cout<<endl;cout<<endl;
	object.display("192.170.11.03");
	cout<<endl;cout<<endl;
	object.display("192.180.11.13");
	cout<<endl;cout<<endl;
	object.display("192.180.11.09");
	cout<<endl;cout<<endl;
	
	return 0;
}
