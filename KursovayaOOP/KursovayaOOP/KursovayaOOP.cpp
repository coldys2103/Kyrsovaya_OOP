#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;


class vControlers
{
public:
	virtual void print_file(string filename)const = 0;
	virtual void print() const = 0;
	virtual double get_price()const = 0;
	virtual int get_id()const = 0;
	virtual string get_modelname()const = 0;
};

struct Tree_Controler
{
	Tree_Controler* left;
	Tree_Controler* right;
	int num;
	vControlers* data;
	template<class D>
	Tree_Controler(int n, D d, Tree_Controler* l = 0, Tree_Controler* r = 0) :num(n), left(l), right(r), data(d) {}
};
Tree_Controler* root;
class BTree
{
public:
	BTree() {
		root = NULL;
	}
	void static add_Controler(Tree_Controler*& t, int n, vControlers* d) {
		if (t == NULL) {
			t = new Tree_Controler(n, d);
		}
		else {
			if (n < t->num) {
				//cout << "<";
				add_Controler(t->left, n, d);

			}
			else {
				add_Controler(t->right, n, d);
				//cout << ">";
			}
		}
	}
	void inorder(Tree_Controler*& t)
	{
		if (t != NULL) {
			inorder(t->left);
			cout << "Номер класса " << t->num << " | "; t->data->print(); cout << endl;
			inorder(t->right);

		}
		//else cout << "t == NULL";
	}
	void price(Tree_Controler*& t, int a, int b)
	{
		if (t != NULL) {

			price(t->left, a, b);
			if (t->data->get_price() > a && t->data->get_price() < b)
			{
				cout << "Подходящий товар: " << t->num << " | "; t->data->print(); cout << endl;
			}
			price(t->right, a, b);

		}
	}
	void price(Tree_Controler*& t, int a)
	{
		if (t != NULL) {

			price(t->left, a);
			if (t->data->get_price() == a)
			{
				cout << "Подходящий товар: " << t->num << " | "; t->data->print(); cout << endl;
			}
			price(t->right, a);

		}
	}
	void finder(Tree_Controler*& t, int a)
	{
		if (t != NULL) {

			finder(t->left, a);
			if (t->data->get_id() == a)
			{
				cout << "Подходящий товар: " << t->num << " | "; t->data->print(); cout << endl;
			}
			finder(t->right, a);

		}
	}
	void Shaker(double a[], int b[], string c[], int n)
	{
		int l = 1, r = n - 1, k = r;
		do {
			for (int j = r; j >= l; j--)
				if (a[j] < a[j - 1]) { swap(a[j], a[j - 1]); swap(b[j], b[j - 1]); swap(c[j], c[j - 1]); k = j; }
			l = k + 1;
			for (int j = l; j <= r; j++)
				if (a[j] < a[j - 1]) { swap(a[j], a[j - 1]); swap(b[j], b[j - 1]); swap(c[j], c[j - 1]); k = r; }
			r = k - 1;
		} while (l <= r);
	}
	int sorter(Tree_Controler*& t, double* price_mass, int* id_mass, string* name_mass, int counter, int* counters)
	{
		if (t != NULL) {
			counter = sorter(t->left, price_mass, id_mass, name_mass, counter, counters);
			price_mass[counter] = t->data->get_price();
			id_mass[counter] = t->data->get_id();
			name_mass[counter] = t->data->get_modelname();
			counters[counter] = 1;
			counter++;
			counter = sorter(t->right, price_mass, id_mass, name_mass, counter, counters);
		}
		return counter;
	}
	void sort_price()
	{
		cout << "______________________________________________________" << endl << endl << endl;
		cout << endl << " Отсортированные цены: " << endl;
		double price_mass[1000];
		int id_mass[1000];
		int counters[1000];
		string name_mass[1000];
		int counter = 0, counter1 = 0;
		sorter(root, price_mass, id_mass, name_mass, counter, counters);
		while (counters[counter] == 1)
		{
			counter++;
		}
		Shaker(price_mass, id_mass, name_mass, counter);
		for (int i = 0; i < counter; i++)
		{
			cout << price_mass[i] << " Модель " << name_mass[i] << " ID " << id_mass[i] << endl;
		}
	}
};
class Controlers : public vControlers
{
	friend class BTree;

public:
	double price = 0, width = 0, hight = 0, weight = 0;
	int id = 0; string modelname = "", brandname = "";
	int* ptrid;
	void print()const { cout << this->brandname << " " << this->modelname << " " << this->price << " " << this->width << " " << this->hight << " " << this->weight << " " << " Указатель на id " << this->ptrid << endl; }
	void print_file(string filename)const { ofstream f; f.open(filename, ios::app); f << '\n' << " Номер класса " << " " << this->id << " | " << this->price << " " << this->width << " " << this->hight << " " << this->weight << " " << this->modelname << " " << this->brandname; f.close(); };
	void addToTree() {
		BTree::add_Controler(root, this->get_id(), this);
	};
	void create(double price, double width, double hight, double weight, string modelname, string brandname, int id)
	{
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->id = id;
		this->ptrid = &id;
		this->modelname = modelname;
		this->brandname = brandname;
	};
	Controlers create_file(char filename[], Controlers C_file) {
		ifstream input;
		try {
			input.open(filename);
			if (!input.is_open())
			{
				throw filename;
			}
		}
		catch (char* filename)
		{
			cout << "Невозможно открыть файл " << filename << " Ending..."; exit(1);
		}
		int ident;
		input >> ident;
		if (ident == 1)
		{
			double d, data1, data2, data3;
			string Data, Data1;
			input >> d;
			input >> data1;
			input >> data2;
			input >> data3;
			input >> Data;
			input >> Data1;
			C_file.create(d, data1, data2, data3, Data, Data1, ident);
			return C_file;
		}
	}
	double get_price()const { return this->price; }
	double get_weight()const { return this->weight; }
	double get_hight()const { return this->hight; }
	double get_width()const { return this->width; }
	string get_modelname()const { return this->modelname; }
	string get_brandname()const { return this->brandname; }
	int get_id()const { return this->id; }
	void set_modelname(string x) { this->modelname = modelname; }
	void set_brandname(string x) { this->brandname = brandname; }
	void set_price(double x) { this->price = x; }
	void set_weight(double x) { this->weight = x; }
	void set_hight(double x) { this->hight = hight; }
	void set_width(double x) { this->width = width; }
	void set_id(int x) { this->id = x; this->ptrid = &id; }
};
class Mouse :public Controlers
{
protected:// Указываю протектед чтобы заного не переписывать эти поля детям
	int mouse_hz = 0, mouse_dpi = 0;
	string mouse_hand = "", mouse_sensor_type = "";
public:
	// Т.к В Tree.data имеет тип *vControlers для сортировки и поиска мне приходится делать некотрые геттеры виртуальными и переписывать их в каждый класс
	double get_price()const { return this->price; }
	string get_modelname()const { return this->modelname; }
	int get_id()const { return this->id; }
	//Потому что доступ я должен получать именно из указателя на виртуальный базовый класс.
	void print()const { cout << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi << " Указатель на id " << this->ptrid << endl; }
	void print_file(string filename)const { ofstream f6; f6.open(filename, ios::app); f6 << '\n' << " Уникальный идентификатор" << " " << this->id << " | " << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; f6.close(); }
	int get_mouse_hz()const { return this->mouse_hz; };
	int get_mouse_dpi()const { return this->mouse_dpi; };
	string get_mouse_hand()const { return this->mouse_hand; }
	string get_mouse_sensor_type()const { return this->mouse_sensor_type; };
	void set_mouse_sensor_type(string x) { this->mouse_sensor_type = x; };
	void set_mouse_hand(string x) { this->mouse_hand = x; };
	void set_mouse_hz(int x) { this->mouse_hz = x; };
	void set_mouse_dpi(int x) { this->mouse_dpi = x; };
	void create(double price, double width, double hight, double weight, string modelname, string brandname, string mouse_hand, string mouse_sensor_type, int mouse_hz, int mouse_dpi, int id)
	{
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->mouse_hand = mouse_hand;
		this->mouse_dpi = mouse_dpi;
		this->mouse_hz = mouse_hz;
		this->modelname = modelname;
		this->brandname = brandname;
		this->mouse_sensor_type = mouse_sensor_type;
		this->id = id;
		this->ptrid = &(this->id);
	};
	Mouse create_file(char filename[], Mouse C_file) {
		ifstream input;
		try {
			input.open(filename);
			if (!input.is_open())
			{
				throw filename;
			}
		}
		catch (char* filename)
		{
			cout << "Невозможно открыть файл " << filename << " Ending..."; exit(1);
		}
		int ident;
		input >> ident;
		if (ident == 2)
		{
			double d, data1, data2, data3;
			string Data, Data1, Data2, Data3;
			int DATA, DATA1;
			input >> d;
			input >> data1;
			input >> data2;
			input >> data3;
			input >> Data;
			input >> Data1;
			input >> Data2;
			input >> Data3;
			input >> DATA;
			input >> DATA1;
			C_file.create(d, data1, data2, data3, Data, Data1, Data2, Data3, DATA, DATA1, ident);
			return C_file;
		}
	}

};
class Optical :public Mouse
{
private:// Это законченный класс поэтому защищаю данные
	string  mouse_svetodiod_type = "", mouse_svetodiod_power = "", mouse_svetodiod_manufacturer = "";
public:
	//
	double get_price()const { return this->price; }
	string get_modelname()const { return this->modelname; }
	int get_id()const { return this->id; }
	//
	void print()const { cout << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Модель светодиода " << this->mouse_svetodiod_type << " Угол обзора светодиода " << mouse_svetodiod_power << " Фирма светодиода " << this->mouse_svetodiod_manufacturer << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi << " Указатель на id " << this->ptrid << endl; }
	void print_file(string filename)const {
		ofstream f1; f1.open(filename, ios::app); f1 << '\n' << " Номер класса " << " " << this->id << " | " << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Модель светодиода " << this->mouse_svetodiod_type << " Угол обзора светодиода " << mouse_svetodiod_power << " Фирма светодиода " << this->mouse_svetodiod_manufacturer << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; f1.close();
	}
	string get_mouse_svetodiod_type() const { return this->mouse_svetodiod_manufacturer; };
	string get_mouse_svetodiod_power() const { return this->mouse_svetodiod_power; };
	string get_mouse_svetodiod_manufacturer() const { return this->mouse_svetodiod_manufacturer; };
	void set_mouse_svetodiod_type(string x) { this->mouse_svetodiod_type = x; };
	void set_mouse_svetodiod_power(string x) { this->mouse_svetodiod_power = x; };
	void set_mouse_svetodiod_manufacturer(string x) { this->mouse_svetodiod_manufacturer = x; };
	void create(double price, double width, double hight, double weight, string modelname, string brandname, string mouse_hand, string mouse_sensor_type, string mouse_svetodiod_type, string mouse_svetodiod_power, string mouse_svetodiod_manufacturer, int mouse_hz, int mouse_dpi, int id)
	{
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->mouse_hand = mouse_hand;
		this->mouse_dpi = mouse_dpi;
		this->mouse_hz = mouse_hz;
		this->modelname = modelname;
		this->brandname = brandname;
		this->mouse_sensor_type = mouse_sensor_type;
		this->id = id;
		this->mouse_svetodiod_type = mouse_svetodiod_type;
		this->mouse_svetodiod_power = mouse_svetodiod_power;
		this->mouse_svetodiod_manufacturer = mouse_svetodiod_manufacturer;
		this->ptrid = &(this->id);
	}
	Optical create_file(char filename[], Optical C_file) {
		ifstream input;
		try {
			input.open(filename);
			if (!input.is_open())
			{
				throw filename;
			}
		}
		catch (char* filename)
		{
			cout << "Невозможно открыть файл " << filename << " Ending..."; exit(1);
		}
		int ident;
		input >> ident;
		if (ident == 3)
		{
			double d, data1, data2, data3;
			string Data, Data1, Data2, Data3, Data4, Data5, Data6;
			int DATA, DATA1;
			input >> d;
			input >> data1;
			input >> data2;
			input >> data3;
			input >> Data;
			input >> Data1;
			input >> Data2;
			input >> Data3;
			input >> Data4;
			input >> Data5;
			input >> Data6;
			input >> DATA;
			input >> DATA1;
			C_file.create(d, data1, data2, data3, Data, Data1, Data2, Data3, Data4, Data5, Data6, DATA, DATA1, ident);
			return C_file;
		}
	}
};
class Trackball : public Mouse
{
private:
	string  mouse_ball_position = "", mouse_ball_size = "";
public:
	//
	double get_price()const { return this->price; }
	string get_modelname()const { return this->modelname; }
	int get_id()const { return this->id; }
	//
	void print()const { cout << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Положение шарика " << this->mouse_ball_position << " Размер шарика " << mouse_ball_size << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi << " Указатель на id " << this->ptrid << endl; }
	void print_file(string filename)const { ofstream f2; f2.open(filename, ios::app); f2 << '\n' << " Номер класса " << " " << this->id << " | " << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Положение шарика " << this->mouse_ball_position << " Размер шарика " << mouse_ball_size << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; f2.close(); }
	string get_mouse_ball_position() const { return this->mouse_ball_position; };
	string get_mouse_ball_size() const { return this->mouse_ball_size; };
	void set_mouse_ball_position(string x) { this->mouse_ball_position = x; };
	void set_mouse_ball_size(string x) { this->mouse_ball_size = x; };
	void create(double price, double width, double hight, double weight, string modelname, string brandname, string mouse_hand, string mouse_sensor_type, string mouse_ball_position, string mouse_ball_size, int mouse_hz, int mouse_dpi, int id)
	{
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->mouse_hand = mouse_hand;
		this->mouse_dpi = mouse_dpi;
		this->mouse_hz = mouse_hz;
		this->modelname = modelname;
		this->brandname = brandname;
		this->mouse_sensor_type = mouse_sensor_type;
		this->id = id;
		this->mouse_ball_position = mouse_ball_position;
		this->mouse_ball_size = mouse_ball_size;
		this->ptrid = &(this->id);
	};
	Trackball create_file(char filename[], Trackball C_file) {
		ifstream input;
		input.open(filename);
		int ident;
		input >> ident;
		if (ident == 4)
		{
			double d, data1, data2, data3;
			string Data, Data1, Data2, Data3, Data4, Data5;
			int DATA, DATA1;
			input >> d;
			input >> data1;
			input >> data2;
			input >> data3;
			input >> Data;
			input >> Data1;
			input >> Data2;
			input >> Data3;
			input >> Data4;
			input >> Data5;
			input >> DATA;
			input >> DATA1;
			C_file.create(d, data1, data2, data3, Data, Data1, Data2, Data3, Data4, Data5, DATA, DATA1, ident);
			return C_file;
		}
	}
};
class Keybord : public Controlers
{
protected:
	int  keys = 0;
	string type = "", lang = "";
public:
	//
	double get_price()const { return this->price; }
	string get_modelname()const { return this->modelname; }
	int get_id()const { return this->id; }
	//
	void print()const { cout << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang << " Указатель на id " << this->ptrid << endl; }
	void print_file(string filename)const { ofstream f3; f3.open(filename, ios::app); f3 << '\n' << " Номер класса " << " " << this->id << " | " << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang; f3.close(); }
	void set_keys(int x) { this->keys = x; }
	void set_type(string x) { this->type = x; }
	void set_lang(string x) { this->lang = x; }
	string get_type()const { return this->type; }
	string get_lang()const { return this->lang; }
	int get_keys()const { return this->keys; }
	void create(double price, double width, double hight, double weight, int keys, string type, string lang, string modelname, string brandname, int id)
	{
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->keys = keys;
		this->type = type;
		this->lang = lang;
		this->modelname = modelname;
		this->brandname = brandname;
		this->id = id;
		this->ptrid = &(this->id);
	};
	Keybord create_file(char filename[], Keybord C_file) {
		ifstream input;
		try {
			input.open(filename);
			if (!input.is_open())
			{
				throw filename;
			}
		}
		catch (char* filename)
		{
			cout << "Невозможно открыть файл " << filename << " Ending..."; exit(1);
		}
		int ident;
		input >> ident;
		if (ident == 5)
		{
			double d, data1, data2, data3;
			string Data, Data1, Data2, Data3;
			int DATA;
			input >> d;
			input >> data1;
			input >> data2;
			input >> data3;
			input >> DATA;
			input >> Data;
			input >> Data1;
			input >> Data2;
			input >> Data3;
			C_file.create(d, data1, data2, data3, DATA, Data, Data1, Data2, Data3, ident);
			return C_file;
		}
	}
};
class Membran :public Keybord
{
private:
	int  membran_clicks;
	string membran_type = "", membran_material = "", membran_form = "";
public:
	//
	double get_price()const { return this->price; }
	string get_modelname()const { return this->modelname; }
	int get_id()const { return this->id; }
	//
	void print()const { cout << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang << " Предел нажатий " << this->membran_clicks << " Форма мембраны " << this->membran_form << " Тип мембраны " << membran_type << " Материал мембраны " << this->membran_material << " Указатель на id " << this->ptrid << endl; }
	void print_file(string filename)const { ofstream f4; f4.open(filename, ios::app); f4 << '\n' << " Номер класса " << " " << this->id << " | " << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang << " Предел нажатий " << this->membran_clicks << " Форма мембраны " << this->membran_form << " Тип мембраны " << membran_type << " Материал мембраны " << this->membran_material; f4.close(); }
	int get_membran_clicks() const { return this->membran_clicks; }
	string get_membran_material() const { return this->membran_material; }
	string get_membran_form() const { return this->membran_form; }
	string get_membran_type()const { return this->membran_type; }
	int set_membran_clicks(int x) { this->membran_clicks = x; };
	string set_membran_material(string x) { this->membran_material = x; }
	string set_membran_form(string x) { this->membran_form = x; }
	string set_membran_type(string x) { this->membran_type = x; }
	void create(double price, double width, double hight, double weight, int keys, string type, string lang, string modelname, string brandname, int membran_clicks, string membran_form, string membran_type, string membran_material, int id)
	{
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->keys = keys;
		this->type = type;
		this->lang = lang;
		this->modelname = modelname;
		this->brandname = brandname;
		this->id = id;
		this->membran_clicks = membran_clicks;
		this->membran_form = membran_form;
		this->membran_material = membran_material;
		this->membran_type = membran_type;
		this->ptrid = &(this->id);
	};
	Membran create_file(char filename[], Membran C_file) {
		ifstream input;
		try {
			input.open(filename);
			if (!input.is_open())
			{
				throw filename;
			}
		}
		catch (char* filename)
		{
			cout << "Невозможно открыть файл " << filename << " Ending..."; exit(1);
		}
		int ident;
		input >> ident;
		if (ident == 6)
		{
			double d, data1, data2, data3;
			string Data, Data1, Data2, Data3, Data4, Data5, Data6;
			int DATA, DATA1;
			input >> d;
			input >> data1;
			input >> data2;
			input >> data3;
			input >> DATA;
			input >> Data;
			input >> Data1;
			input >> Data2;
			input >> Data3;
			input >> DATA1;
			input >> Data4;
			input >> Data5;
			input >> Data6;
			C_file.create(d, data1, data2, data3, DATA, Data, Data1, Data2, Data3, DATA1, Data4, Data5, Data6, ident);
			return C_file;
		}
	}
};
class Mechanical :public Keybord {
private:
	double switch_work_time = 0;
	int switch_press_power = 0, switch_clicks = 0;
	string switch_color = "", switch_type = "";
public:
	//
	double get_price()const { return this->price; }
	string get_modelname()const { return this->modelname; }
	int get_id()const { return this->id; }
	//
	void print()const { cout << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang << " Цвет переключателей " << this->switch_color << " Тип переключателей " << switch_type << " Предел нажатий " << this->switch_clicks << " Сила нажатия " << switch_press_power << " Время срабатывания " << switch_work_time << " Указатель на id " << this->ptrid << endl; }
	void print_file(string filename)const { ofstream f5; f5.open(filename, ios::app); f5 << '\n'; f5 << " Номер класса" << " " << this->id << " | " << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang << " Цвет переключателей " << this->switch_color << " Тип переключателей " << switch_type << " Предел нажатий " << this->switch_clicks << " Сила нажатия " << switch_press_power << " Время срабатывания " << switch_work_time; f5.close(); }
	void set_switch_clicks(int x) { this->switch_clicks = x; };
	void set_switch_press_power(double x) { this->switch_clicks = x; };
	void set_switch_work_time(int x) { this->switch_work_time = x; };
	void set_switch_color(string x) { this->switch_color = x; };
	void set_switch_type(string x) { this->switch_type = x; };
	int get_switch_clicks()const { return this->switch_clicks; };
	int get_switch_press_power()const { return this->switch_press_power; };
	double get_switch_work_time()const { return this->switch_work_time; };
	string get_switch_color()const { return this->switch_color; };
	string get_switch_type()const { return this->switch_type; };
	void create(double price, double width, double hight, double weight, int keys, string type, string lang, string modelname, string brandname, int switch_clicks, string switch_color, string switch_type, int switch_work_time, double switch_press_power, int id)
	{
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->keys = keys;
		this->type = type;
		this->lang = lang;
		this->modelname = modelname;
		this->brandname = brandname;
		this->id = id;
		this->switch_clicks = switch_clicks;
		this->switch_color = switch_color;
		this->switch_press_power = switch_press_power;
		this->switch_type = switch_type;
		this->switch_work_time = switch_work_time;
		this->ptrid = &(this->id);
	};
	Mechanical create_file(char filename[], Mechanical C_file) {
		ifstream input;
		try {
			input.open(filename);
			if (!input.is_open())
			{
				throw filename;
			}
		}
		catch (char* filename)
		{
			cout << "Невозможно открыть файл " << filename << " Ending..."; exit(1);
		}
		int ident;
		input >> ident;
		if (ident == 7)
		{
			double d, data1, data2, data3, data4;
			string Data, Data1, Data2, Data3, Data4, Data5;
			int DATA, DATA1, DATA2;

			input >> d;
			input >> data1;
			input >> data2;
			input >> data3;
			input >> DATA;
			input >> Data;
			input >> Data1;
			input >> Data2;
			input >> Data3;
			input >> DATA1;
			input >> Data4;
			input >> Data5;
			input >> data4;
			input >> DATA2;
			C_file.create(d, data1, data2, data3, DATA, Data, Data1, Data2, Data3, DATA1, Data4, Data5, data4, DATA2, ident);
			return C_file;
		}
	}
};
int main() {
	setlocale(LC_ALL, "RU");
	vControlers* ptr;
	Controlers s, s1;
	Mouse m, m1;
	Trackball tm, tm1;
	Keybord k, k1;
	Membran memk, memk1;
	Mechanical mechk, mechk1;
	Optical om, om1;
	char S1[] = "Controlers_input.txt";
	char S2[] = "Mouse_input.txt";
	char S3[] = "Optical_input.txt";
	char S4[] = "Trackball_input.txt";
	char S5[] = "Keybord_input.txt";
	char S6[] = "Membran_input.txt";
	char S7[] = "Mechanical_input.txt";
	s.create(1, 1, 1, 1, "kek", "wait", 1);
	m.create(2340, 10, 15, 200, "Mini Viper", "Razer", "Правая", "Оптическая", 1000, 8600, 2);
	om.create(499, 22, 30, 86, "Scroll Too 200", "Genuis", "Правая", "Оптическая-Светодиодная", "Инфракрасный", "30 градусов", "KINGBRIGHT", 1000, 8600, 3);
	tm.create(4799, 25, 27, 300, "Ergo M575", "Logitech", "Правая", "Трекбол", "Слева", "Небольшой", 1000, 10000, 4);
	k.create(5, 6, 7, 8, 87, "mechanical", "russian", "AllowFPS", "HyperX", 5);
	memk.create(299, 136.7, 22, 400, 104, "Мембранная", "Русско-Английская", "Next HB-440", "Defender", 50000000, "Классическая", "Купольная", "Силикон", 6);
	mechk.create(4263.83, 122, 10, 70, 87, "Механическая", "Русско-Английская", "K7", "MACHENIKE", 50000000, "Синие", "Тактильные", 2, 50, 7);
	s1 = s1.create_file(S1, s1);
	m1 = m1.create_file(S2, m1);
	om1 = om1.create_file(S3, om1);
	tm1 = tm1.create_file(S4, tm1);
	k1 = k1.create_file(S5, k1);
	memk1 = memk1.create_file(S6, memk1);
	mechk1 = mechk1.create_file(S7, mechk1);
	ptr = &s;
	ptr->print();
	ptr->print_file("s.txt");
	ptr = &s1;
	ptr->print();
	ptr->print_file("s1.txt");
	ptr = &m;
	ptr->print();
	ptr->print_file("m.txt");
	ptr = &m1;
	ptr->print();
	ptr->print_file("m1.txt");
	ptr = &om;
	ptr->print();
	ptr->print_file("om.txt");
	ptr = &om1;
	ptr->print();
	ptr->print_file("om1.txt");
	ptr = &tm;
	ptr->print();
	ptr->print_file("tm.txt");
	ptr = &tm1;
	ptr->print();
	ptr->print_file("tm1.txt");
	ptr = &k;
	ptr->print();
	ptr->print_file("k.txt");
	ptr = &k1;
	ptr->print();
	ptr->print_file("k1.txt");
	ptr = &memk;
	ptr->print();
	ptr->print_file("memk.txt");
	ptr = &memk1;
	ptr->print();
	ptr->print_file("memk1.txt");
	ptr = &mechk;
	ptr->print();
	ptr->print_file("mechk.txt");
	ptr = &mechk1;
	ptr->print();
	ptr->print_file("mechk1.txt");
	cout << m.get_id();
	cout << endl << endl << endl;
	BTree bt;
	s.addToTree();
	s1.addToTree();
	m.addToTree();
	om.addToTree();
	tm.addToTree();
	k.addToTree();
	memk.addToTree();
	mechk.addToTree();
	m1.addToTree();
	om1.addToTree();
	tm1.addToTree();
	k1.addToTree();
	memk1.addToTree();
	mechk1.addToTree();
	bt.inorder(root);
	cout << endl << endl << endl;
	cout << "price(1param) :";
	bt.price(root, 4799);
	cout << "price(2param) :";
	bt.price(root, 3000, 5000);
	cout << "finder :";
	bt.finder(root, 2);
	bt.sort_price();

	cout << "gg";
}
