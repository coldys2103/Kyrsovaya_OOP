#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

class interf
{
public:
virtual void print_file(string filename) const=0;
virtual void print() const=0;
virtual int get_id() const = 0;
virtual double get_price() const = 0;
virtual double get_width() const = 0;
virtual double get_hight() const = 0;
virtual int get_keys() const = 0;
virtual string get_lang() const = 0;
virtual string get_type() const = 0;
virtual string get_brandname() const = 0;
virtual string get_modelname() const = 0;
virtual int get_membran_clicks() const = 0;
virtual string get_membran_material() const = 0;
virtual string get_membran_form() const = 0;
virtual int get_switch_clicks() const = 0;
virtual int get_switch_press_power() const = 0;
virtual double get_switch_work_time() const = 0;
virtual string get_switch_color() const = 0;
virtual string get_switch_type() const = 0;
virtual string get_mouse_hand() const = 0;
virtual int get_mouse_hz() const = 0;
virtual int get_mouse_dpi() const = 0;
virtual string get_mouse_sensor_type() const = 0;
virtual string get_mouse_svetodiod_type() const = 0;
virtual string get_mouse_svetodiod_power() const = 0;
virtual string get_mouse_svetodiod_manufacturer() const = 0;
virtual string get_mouse_ball_position() const = 0;
virtual string get_mouse_ball_size() const = 0;
virtual string get_class_name() const = 0;
virtual void set_class_name() {};
virtual void set_mouse_ball_position() {};
virtual void set_mouse_ball_size() {};
virtual void set_mouse_svetodiod_type() {};
virtual void set_mouse_svetodiod_power() {};
virtual void set_mouse_svetodiod_manufacturer() {};
virtual void set_mouse_sensor_type() {};
virtual void set_mouse_hz() {};
virtual void set_mouse_dpi() {};
virtual void set_mouse_hand() {};
virtual void set_id() {};
virtual void set_price() {};
virtual void set_width() {};
virtual void set_hight() {};
virtual void set_keys() {};
virtual void set_land() {};
virtual void set_type() {};
virtual void set_brandname() {};
virtual void set_modelname() {};
virtual void set_membran_clicks() {};
virtual void set_membran_material() {};
virtual void set_membran_form() {};
virtual void set_switch_clicks() {};
virtual void set_switch_press_power() {};
virtual void set_switch_work_time() {};
virtual void set_switch_color() {};
virtual void set_switch_type() {};

};

//Класс Средств управления компьютером в целом
class Controlers : public interf
{
private:	
	double price=0, width = 0, hight = 0, weight = 0;
	int id = 0;
	string modelname, brandname,class_name;
public:
	//используемые методы
	void print()const { cout << this->brandname<<" "<<this->modelname<<" "<<this->price << " " << this->width << " " << this->hight << " " << this->weight << " "; }
	void print_file(string filename)const { ofstream f(filename); f.open("Controlers_output.txt", ios::app); f<<'\n'<<" Уникальный идентификатор "<< " " << this->id<<" | " << this->price << " " << this->width << " " << this->hight << " " << this->weight << " "; f.close();}
	double get_price()const{return this->price;}
	double get_weight()const{return this->weight;}
	double get_hight()const{return this->hight;}
	double get_width()const	{return this->width;}
	string get_modelname()const { return this->modelname; }
	string get_brandname()const { return this->brandname; }
	int get_id()const {return this->id;}
	int get_mouse_hz()const { return NULL; };
	int get_mouse_dpi()const { return NULL; };
	string get_mouse_hand()const { return NULL; }
	string get_mouse_sensor_type()const { return NULL; };
	string get_mouse_svetodiod_type() const { return NULL; };
	string get_mouse_svetodiod_power() const { return NULL; };
	string get_mouse_svetodiod_manufacturer() const { return NULL; };
	string get_mouse_ball_position() const { return NULL; };
	string get_mouse_ball_size() const { return NULL; };
	string get_class_name()const { return this->class_name; }
	void set_class_name(string x) { this->class_name = x; }
	void set_mouse_ball_position(string x) {};
	void set_mouse_ball_size(string x) {};
	void set_mouse_svetodiod_type(string x) {};
	void set_mouse_svetodiod_power(string x) {};
	void set_mouse_svetodiod_manufacturer(string x) {};
	void set_mouse_sensor_type(string x) {};
	void set_mouse_hand(string x) { this->price = -1; };
	void set_mouse_hz(int x) { };
	void set_mouse_dpi(int x) { };
	void set_modelname(string x) { }
	void set_brandname(string x) { }
	void set_price(double x) { this->price = x; };
	void set_weight(double x) { this->weight = x; };
	void set_hight(double x) { this->hight = hight; };
	void set_width(double x) { this->width = width; };
	void set_id(int x) { this->id = x; };
	// не используемые для этого класса функции, но нужно их изменить чтобы класс не стал абстрактным
	int get_switch_clicks()const { return NULL; };
	int get_switch_press_power() const { return NULL; };
	double get_switch_work_time() const { return NULL; };
	string get_switch_color()const { return NULL; };
	string get_switch_type()const { return NULL; };
	int get_membran_clicks() const { return NULL; };
	string get_membran_material() const { return NULL; };
	string get_membran_form() const { return NULL; };
	string get_lang()const { return NULL; };
	int	   get_keys()const { return NULL; };
	string get_type()const { return NULL; };
	void set_keys() {};
	void set_land() {};
	void set_type() {};

	void set_switch_clicks() {};
	void set_switch_press_power() {};
	void set_switch_work_time() {};
	void set_switch_color() {};
	void set_switch_type() {};

	
	//
	string classname = "Controlers";
	void create(double price, double width, double hight, double weight,string modelname,string brandname,int id)
	{
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->id = id;
		this->modelname = modelname;
		this->brandname = brandname;
	};
	Controlers()
	{
		double random = 0;
		random = rand() % 5;
		create(random, random, random, random, "kek","wait",random);
	}
	Controlers(double price, double width, double hight, double weight, int id)
	{
		create(price, width, hight, weight,modelname,brandname,id);
	}
};
//Класс Компьютерных мышей
class Mouse :public Controlers
{
private:
	double price = 0, width = 0, hight = 0, weight = 0;
	int id = 0,mouse_hz = 0,mouse_dpi = 0;
	string mouse_hand ="", modelname = "", brandname = "", mouse_sensor_type = "",class_name="Mouse";
public:
	void print()const { cout << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand <<" Тип сенсора "<<this->mouse_sensor_type << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; }
	void print_file(string filename)const{ofstream f6(filename); f6.open("Mouse_output.txt", ios::app); f6<<'\n'<<" Уникальный идентификатор"<<" "<< this->id<<" | "<<   "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; f6.close();}
	double get_price()const { return this->price; }
	double get_weight()const { return this->weight; }
	double get_hight()const { return this->hight; }
	double get_width()const { return this->width; }
	int get_id()const { return this->id; }
	int get_mouse_hz() { return this->mouse_hz; };
	int get_mouse_dpi() { return this->mouse_dpi; };
	string get_modelname()const { return this->modelname; }
	string get_brandname()const { return this->brandname; }
	string get_mouse_hand()const { return this->mouse_hand; }
	string get_mouse_sensor_type()const { return this->mouse_sensor_type; };
	string get_class_name()const { return this->class_name; }
	void set_class_name(string x) { this->class_name = x; }
	void set_mouse_sensor_type(string x) { this->mouse_sensor_type = x; };
	void set_mouse_hand(string x) { this->mouse_hand = x; };
	void set_mouse_hz(int x) { this->mouse_hz = x; };
	void set_mouse_dpi(int x) { this->mouse_dpi = x; };
	void set_price(double x) { this->price = x; };
	void set_weight(double x) { this->weight = x; };
	void set_hight(double x) { this->hight = hight; };
	void set_width(double x) { };
	void set_id(int x) { this->id = x; };
	void set_modelname(string x) { this->modelname = x; };
	void set_brandname(string x) { this->brandname = x; };
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
	};
};
//Класс оптических мышей
class Optical :public Mouse
{
private:
	double price=0, width = 0, hight = 0, weight = 0;
	int id = 0, mouse_hz = 0, mouse_dpi = 0;
	string mouse_hand = "", modelname = "", brandname = "",mouse_sensor_type = "",mouse_svetodiod_type = "",mouse_svetodiod_power = "",mouse_svetodiod_manufacturer = "",class_name="Optical mouse";
public:
	void print()const { cout << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type <<" Модель светодиода "<<this->mouse_svetodiod_type<<" Угол обзора светодиода " <<mouse_svetodiod_power<<" Фирма светодиода " <<this->mouse_svetodiod_manufacturer<< " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; }
	void print_file(string filename)const {
		ofstream f1(filename); f1.open("Optical_output.txt", ios::app); f1<<'\n'<<" Уникальный идентификатор "<< " " << this->id<<" | "<<   "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Модель светодиода " << this->mouse_svetodiod_type << " Угол обзора светодиода " << mouse_svetodiod_power << " Фирма светодиода " << this->mouse_svetodiod_manufacturer << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; f1.close();
	}
	double get_price()const { return this->price; }
	double get_weight()const { return this->weight; }
	double get_hight()const { return this->hight; }
	double get_width()const { return this->width; }
	int get_id()const { return this->id; }
	int get_mouse_hz() { return this->mouse_hz; };
	int get_mouse_dpi() { return this->mouse_dpi; };
	string get_modelname()const { return this->modelname; }
	string get_brandname()const { return this->brandname; }
	string get_mouse_hand()const { return this->mouse_hand; }
	string get_mouse_sensor_type()const { return this->mouse_sensor_type; };
	string get_mouse_svetodiod_type() const { return this->mouse_svetodiod_manufacturer; };
	string get_mouse_svetodiod_power() const { return this->mouse_svetodiod_power; };
	string get_mouse_svetodiod_manufacturer() const { return this->mouse_svetodiod_manufacturer; };
	string get_class_name()const { return this->class_name; }
	void set_class_name(string x) { this->class_name = x; }
	void set_mouse_svetodiod_type(string x) { this->mouse_svetodiod_type = x; };
	void set_mouse_svetodiod_power(string x) { this->mouse_svetodiod_power = x; };
	void set_mouse_svetodiod_manufacturer(string x) { this->mouse_svetodiod_manufacturer = x; };
	void set_mouse_hand(string x) { this->mouse_hand = x; };
	void set_mouse_hz(int x) { this->mouse_hz = x; };
	void set_mouse_dpi(int x) { this->mouse_dpi = x; };
	void set_price(double x) { this->price = x; };
	void set_weight(double x) { this->weight = x; };
	void set_hight(double x) { this->hight = hight; };
	void set_width(double x) { };
	void set_id(int x) { this->id = x; };
	void set_modelname(string x) { this->modelname = x; };
	void set_brandname(string x) { this->brandname = x; };
	void create(double price, double width, double hight, double weight, string modelname, string brandname, string mouse_hand,string mouse_sensor_type,string mouse_svetodiod_type,string mouse_svetodiod_power, string mouse_svetodiod_manufacturer, int mouse_hz, int mouse_dpi, int id)
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
	};
};
//Класс трекболл-мышей 
class Trackball : public Mouse 
{
private:
	double price = 0, width, hight = 0, weight = 0;
	int id = 0, mouse_hz = 0, mouse_dpi = 0;
	string mouse_hand="", modelname = "", brandname = "", mouse_sensor_type = "", mouse_ball_position = "", mouse_ball_size = "",class_name="Trackball mouse";
public:	
	void print()const { cout << "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Положение шарика " << this->mouse_ball_position << " Размер шарика " << mouse_ball_size << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; }
	void print_file(string filename)const { ofstream f2(filename); f2.open("Trackball_output.txt", ios::app); f2<<'\n'<<" Уникальный идентификатор "<< " " << this->id<<" | "<<   "Мышка" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Рабочая рука " << this->mouse_hand << " Тип сенсора " << this->mouse_sensor_type << " Положение шарика " << this->mouse_ball_position << " Размер шарика " << mouse_ball_size << " Герцовка мышки " << this->mouse_hz << " DPI мыши " << this->mouse_dpi; f2.close(); }
	string get_mouse_ball_position() const { return this->mouse_ball_position; };
	string get_mouse_ball_size() const { return this->mouse_ball_size; };
	void set_mouse_ball_position(string x) { this->mouse_ball_position = x; };
	void set_mouse_ball_size(string x) { this->mouse_ball_size = x; };
	double get_price()const { return this->price; }
	double get_weight()const { return this->weight; }
	double get_hight()const { return this->hight; }
	double get_width()const { return this->width; }
	int get_id()const { return this->id; }
	int get_mouse_hz() { return this->mouse_hz; };
	int get_mouse_dpi() { return this->mouse_dpi; };
	string get_modelname()const { return this->modelname; }
	string get_brandname()const { return this->brandname; }
	string get_mouse_hand()const { return this->mouse_hand; }
	string get_mouse_sensor_type()const { return this->mouse_sensor_type; };
	string get_class_name()const { return this->class_name; }
	void set_class_name(string x) { this->class_name = x; }
	void set_mouse_hand(string x) { this->mouse_hand = x; };
	void set_mouse_hz(int x) { this->mouse_hz = x; };
	void set_mouse_dpi(int x) { this->mouse_dpi = x; };
	void set_price(double x) { this->price = x; };
	void set_weight(double x) { this->weight = x; };
	void set_hight(double x) { this->hight = hight; };
	void set_width(double x) { };
	void set_id(int x) { this->id = x; };
	void set_modelname(string x) { this->modelname = x; };
	void set_brandname(string x) { this->brandname = x; };

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
	};
};
//Класс Клавиатур
class Keybord : public Controlers
{
private:
	double price = 0, width = 0, hight = 0, weight = 0;
	int id = 0, keys = 0;
	string modelname = "", brandname = "",type = "",lang = "",class_name="Keybord";

public:
	//используемые методы
	void print()const { cout << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang; }
	void print_file(string filename)const { ofstream f3(filename); f3.open("Keybord_output.txt", ios::app); f3<<'\n'<<" Уникальный идентификатор "<< " " << this->id<<" | "<<    "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang; f3.close(); }
	double get_price()const { return this->price; }
	double get_weight()const { return this->weight; }
	double get_hight()const { return this->hight; }
	double get_width()const { return this->width; }
	int get_id()const { return this->id; }
	int get_keys()const { return this->keys; }
	string get_class_name()const { return this->class_name; }
	void set_class_name(string x) { this->class_name = x; }
	void set_price(double x) { this->price = x; };
	void set_weight(double x) { this->weight = x; };
	void set_hight(double x) { this->hight = hight; };
	void set_id(int x) { this->id = x; };
	void set_keys(int x) { this->keys = x; }
	void set_type(string x) { this->type = x; }
	void set_lang(string x) { this->lang = x; }
	void set_modelname(string x) { this->modelname = x; }
	void set_brandname(string x) { this->brandname = x; }

	void set_width(double x) { this->width = width; };

	string get_type()const { return this->type; }
	string get_lang()const { return this->lang; }
	string get_modelname()const { return this->modelname; }
	string get_brandname()const { return this->brandname; }

	void create(double price, double width, double hight, double weight,int keys,string type,string lang,string modelname,string brandname, int id)
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
	};

	




};
//Класс Мембранных клавиатур
class Membran :public Keybord
{
private:
	double price, width, hight, weight;
	int id, keys,membran_clicks;
	string type = "", modelname = "", brandname = "", lang = "",membran_type = "",membran_material = "",membran_form = "",class_name="Membran keybord";
public:
	
	void print()const { cout << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang << " Предел нажатий " << this->membran_clicks << " Форма мембраны " << this->membran_form <<" Тип мембраны "<<membran_type<< " Материал мембраны " << this->membran_material; }
	void print_file(string filename)const { ofstream f4(filename); f4.open("Membran_output.txt", ios::app); f4<<'\n'<<" Уникальный идентификатор "<< " " << this->id<<" | "<<   "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang << " Предел нажатий " << this->membran_clicks << " Форма мембраны " << this->membran_form<<" Тип мембраны " << membran_type << " Материал мембраны " << this->membran_material; f4.close(); }
	double get_price()const { return this->price; }
	double get_weight()const { return this->weight; }
	double get_hight()const { return this->hight; }
	double get_width()const { return this->width; }
	int get_id()const { return this->id; }
	string get_class_name()const { return this->class_name; }
	void set_class_name(string x) { this->class_name = x; }
	void set_price(double x) { this->price = x; };
	void set_weight(double x) { this->weight = x; };
	void set_hight(double x) { this->hight = hight; };
	void set_id(int x) { this->id = x; };
	void set_keys(int x) { this->keys = x; }
	void set_type(string x) { this->type = x; }
	void set_lang(string x) { this->lang = x; }
	void set_modelname(string x) {this->modelname=x ; }
	void set_brandname(string x) { this->brandname=x; }

	string get_type()const { return this->type; }
	string get_lang()const { return this->lang; }
	string get_modelname()const { return this->modelname; }
	string get_brandname()const { return this->brandname; }
	int get_keys()const { return this->keys; }
	int get_membran_clicks() const { return this->membran_clicks; };
	string get_membran_material() const { return this->membran_material; };
	string get_membran_form() const { return this->membran_form; };
	
	void create(double price, double width, double hight, double weight, int keys, string type, string lang, string modelname, string brandname,int membran_clicks,string membran_form, string membran_type, string membran_material, int id)
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
	};


};
//Класс Механических Клавиатур
class Mechanical :public Keybord {
private: 
	double price = 0, width = 0, hight = 0, weight = 0,switch_work_time = 0;
	int id=0, keys = 0,switch_press_power = 0,switch_clicks = 0;
	string type = "", modelname = "", brandname = "", lang = "", switch_color = "", switch_type = "", class_name="Mechanical keybord";
public:
	void print()const{ cout << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang <<" Цвет переключателей "<< this->switch_color<<" Тип переключателей "<<switch_type<< " Предел нажатий " << this->switch_clicks<<" Сила нажатия "<<switch_press_power<<" Время срабатывания "<< switch_work_time; }
	void print_file(string filename)const { ofstream f5(filename); f5.open("Mechanical_output.txt", ios::app); f5 << '\n'; f5 << " Уникальный идентификатор" << " " << this->id << " | " << "Клавиатура" << " " << this->brandname << " " << this->modelname << " Цена " << this->price << " Ширина " << this->width << " Высота " << this->hight << " Вес " << this->weight << " Кол-во клавиш " << this->keys << " Тип " << this->type << " Язык расскладки " << this->lang << " Цвет переключателей " << this->switch_color << " Тип переключателей " << switch_type << " Предел нажатий " << this->switch_clicks << " Сила нажатия " << switch_press_power << " Время срабатывания " << switch_work_time; f5.close(); }
	double get_price()const { return this->price; }
	double get_weight()const { return this->weight; }
	double get_hight()const { return this->hight; }
	double get_width()const { return this->width; }
	int get_id()const { return this->id; }
	string get_class_name()const { return this->class_name; }
	void set_class_name(string x) { this->class_name = x; }
	void set_price(double x) { this->price = x; };
	void set_weight(double x) { this->weight = x; };
	void set_hight(double x) { this->hight = hight; };
	void set_id(int x) { this->id = x; };
	void set_keys(int x) { this->keys = x; }
	void set_type(string x) { this->type = x; }
	void set_lang(string x) { this->lang = x; }
	void set_modelname(string x) { this->modelname = x; }
	void set_brandname(string x) { this->brandname = x; }
	int get_keys()const { return this->keys; }
	string get_type()const { return this->type; }
	string get_lang()const { return this->lang; }
	string get_modelname()const { return this->modelname; }
	string get_brandname()const { return this->brandname; }
	int get_switch_clicks()const { return this->switch_clicks; };
	int get_switch_press_power()const { return this->switch_press_power; };
	double get_switch_work_time()const { return this->switch_work_time; };
	string get_switch_color()const { return this->switch_color; };
	string get_switch_type()const { return this->switch_type; };
	int get_mouse_hz() { return NULL; };
	int get_mouse_dpi() { return NULL; };
	string get_mouse_hand() { return NULL; }
	void set_mouse_hand(string x) {};
	void set_mouse_hz(int x) {};
	void set_mouse_dpi(int x) {};
	void set_width(double x) { this->width = width; };
	void set_switch_clicks(int x) { this->switch_clicks = x; };
	void set_switch_press_power(double x) { this->switch_clicks = x; };
	void set_work_time(int x) { this->switch_work_time = x; };
	void set_switch_color(string x) { this->switch_color = x; };
	void set_switch_type(string x) { this->switch_type = x; };

	void create(double price, double width, double hight, double weight, int keys, string type, string lang, string modelname, string brandname, int switch_clicks, string switch_color, string switch_type,int switch_work_time, double switch_press_power, int id)
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
	};
};

struct Tree_Controler
{
	Tree_Controler* left;
	Tree_Controler* right;
	int num;
	Controlers data;
	template<class D>
	Tree_Controler(int n, D d, Tree_Controler* l = 0, Tree_Controler* r = 0) :num(n), left(l), right(r), data(d) {}
};
struct Tree_Keybord
{
	Tree_Keybord* left;
	Tree_Keybord* right;
	int num;
	Keybord data;
	template<class D>
	Tree_Keybord(int n, D d, Tree_Keybord* l = 0, Tree_Keybord* r = 0) :num(n), left(l), right(r), data(d) {}
};
struct Tree_Membran
{
	Tree_Membran* left;
	Tree_Membran* right;
	int num;
	Membran data;
	template<class D>
	Tree_Membran(int n, D d, Tree_Membran* l = 0, Tree_Membran* r = 0) :num(n), left(l), right(r), data(d) {}
};
struct Tree_Mechanical
{
	Tree_Mechanical* left;
	Tree_Mechanical* right;
	int num;
	Mechanical data;
	template<class D>
	Tree_Mechanical(int n, D d, Tree_Mechanical* l = 0, Tree_Mechanical* r = 0) :num(n), left(l), right(r), data(d) {}
};
struct Tree_Mouse
{
	Tree_Mouse* left;
	Tree_Mouse* right;
	int num;
	Mouse data;
	template<class D>
	Tree_Mouse(int n, D d, Tree_Mouse* l = 0, Tree_Mouse* r = 0) :num(n), left(l), right(r), data(d) {}
};
struct Tree_Optical
{
	Tree_Optical* left;
	Tree_Optical* right;
	int num;
	Optical data;
	template<class D>
	Tree_Optical(int n, D d, Tree_Optical* l = 0, Tree_Optical* r = 0) :num(n), left(l), right(r), data(d) {}
};
struct Tree_Trackball
{
	Tree_Trackball* left;
	Tree_Trackball* right;
	int num;
	Trackball data;
	template<class D>
	Tree_Trackball(int n, D d, Tree_Trackball* l = 0, Tree_Trackball* r = 0) :num(n), left(l), right(r), data(d) {}
};



class BTree
{
	Tree_Controler* root;
	Tree_Keybord* root1;
	Tree_Membran* root2;
	Tree_Mechanical* root3;
	Tree_Mouse* root4;
	Tree_Optical* root5;
	Tree_Trackball* root6;
public:
	BTree() {
		root = NULL;
		root1 = NULL;
		root2 = NULL;
		root3 = NULL;
		root4 = NULL;
		root5 = NULL;
		root6 = NULL;
	}
	
	
		void add_Controlers(Tree_Controler* &t, int n, Controlers d) {
			if (t == NULL) {
					t = new Tree_Controler(n, d);

			}
			else {
				if (n < t->num) {
					//cout << "<";
					add_Controlers(t->left, n, d);

				}
				else {
					add_Controlers(t->right, n, d);
					//cout << ">";
				}
			}

		}
		void add_Keybord(Tree_Keybord* &t1,int n, Keybord d) {
			if (t1 == NULL) {
				t1 = new Tree_Keybord(n, d);

			}
			else {
				if (n < t1->num) {
					//cout << "<";
					add_Keybord(t1->left, n, d);

				}
				else {
					add_Keybord(t1->right, n, d);
					//cout << ">";
				}
			}
		}
		void add_Membran(Tree_Membran*& t2, int n, Membran d) {
			if (t2 == NULL) {
				t2 = new Tree_Membran(n, d);

			}
			else {
				if (n < t2->num) {
					//cout << "<";
					add_Membran(t2->left, n, d);

				}
				else {
					add_Membran(t2->right, n, d);
					//cout << ">";
				}
			}
		}
		void add_Mechanical(Tree_Mechanical*& t3, int n, Mechanical d) {
			if (t3 == NULL) {
				t3 = new Tree_Mechanical(n, d);

			}
			else {
				if (n < t3->num) {
					//cout << "<";
					add_Mechanical(t3->left, n, d);

				}
				else {
					add_Mechanical(t3->right, n, d);
					//cout << ">";
				}
			}
		}
		void add_Mouse(Tree_Mouse*& t4, int n, Mouse d) {
			if (t4 == NULL) {
				t4 = new Tree_Mouse(n, d);

			}
			else {
				if (n < t4->num) {
					//cout << "<";
					add_Mouse(t4->left, n, d);

				}
				else {
					add_Mouse(t4->right, n, d);
					//cout << ">";
				}
			}
		}
		void add_Optical(Tree_Optical*& t5, int n, Optical d) {
			if (t5== NULL) {
				t5 = new Tree_Optical(n, d);

			}
			else {
				if (n < t5->num) {
					//cout << "<";
					add_Optical(t5->left, n, d);

				}
				else {
					add_Optical(t5->right, n, d);
					//cout << ">";
				}
			}
		}
		void add_Trackball(Tree_Trackball*& t6, int n, Trackball d) {
			if (t6 == NULL) {
				t6 = new Tree_Trackball(n, d);

			}
			else {
				if (n < t6->num) {
					//cout << "<";
					add_Trackball(t6->left, n, d);

				}
				else {
					add_Trackball(t6->right, n, d);
					//cout << ">";
				}
			}
		}
		void add_controler(int n, Controlers d)
		{
			add_Controlers(root, n, d);
		}
		void add_keybord(int n, Keybord d)
		{
			add_Keybord(root1, n, d);
		}
		void add_membran(int n, Membran d)
		{
			add_Membran(root2, n, d);
		}
		void add_mechanical(int n, Mechanical d)
		{
			add_Mechanical(root3, n, d);
		}
		void add_mouse(int n, Mouse d)
		{
			add_Mouse(root4, n, d);
		}
		void add_optical(int n, Optical d)
		{
			add_Optical(root5, n, d);
		}
		void add_trackball(int n, Trackball d)
		{
			add_Trackball(root6, n, d);
		}
	template <class Tree,typename string>
	void inorder(Tree*& t,string f)
	{
		if (t != NULL) {
			inorder(t->left,f);
			cout << "Уникальный номер " << t->num << " | "; t->data.print(); cout << endl;
			t->data.print_file(f);
			inorder(t->right,f);

		}
		//else cout << "t == NULL";
	}
	template<class Tree,typename A,typename B>
	void price(Tree*& t,A a,B b)
	{
		if (t != NULL) {

			price(t->left,a,b);
			if (t->data.get_price() > a && t->data.get_price() < b)
			{
				cout << "Подходящий товар: " << t->num << " | "; t->data.print(); cout << endl;
			}
			price(t->right,a,b);

		}
	}
	template<class Tree,typename A>
	void price(Tree*& t, A a)
	{
		if (t != NULL) {

			price(t->left, a);
			if (t->data.get_price()== a)
			{
				cout << "Подходящий товар: " << t->num << " | "; t->data.print(); cout << endl;
			}
			price(t->right, a);

		}
	}
	template<class Tree, typename type,typename type2,typename type3,typename kek>
	int sorter(Tree*& t, type *price_mass, type2 *id_mass,type3 *name_mass, kek counter)
	{
		if (t != NULL) {
			price_mass[counter] = t->data.get_price();
			id_mass[counter] = t->data.get_id();
			name_mass[counter] = t->data.get_modelname();
			counter++;
			sorter(t->left,price_mass,id_mass,name_mass,counter++);
			sorter(t->right, price_mass, id_mass, name_mass, counter++);
		}
		return counter;
		//else cout << "t == NULL";
	}
	template<class Tree, typename string>
	void finder(Tree*& t, string x)
	{
		if (t != NULL) {

			finder(t->left, x);
			if (t->data.get_class_name() == x)
			{
				cout << "Подходящий товар: " << t->num << " | "; cout<<t->data.get_modelname()<<" "<<t->data.get_brandname()<<" "<<t->data.get_price()<< endl;
			}
			finder(t->right, x);

		}
	}
	void Shaker(int a[],int b[],string c[], int n)
	{
		int l = 1, r = n - 1, k = r;
		do {
			for (int j = r; j >= l; j--)
				if (a[j] < a[j - 1]) { swap(a[j], a[j - 1]); swap(b[j], b[j - 1]);swap(c[j],c[j-1]); k = j; }
			l = k + 1;
			for (int j = l; j <= r; j++)
				if (a[j] < a[j - 1]) { swap(a[j], a[j - 1]); swap(b[j], b[j - 1]); swap(c[j], c[j - 1]); k = r; }
			r = k - 1;
		} while (l <= r);
	}
	template<typename A,typename B>
	void find_price(A a,B b)
	{
		cout <<endl<< "Товары стоимостью от " << a << " до " << b<< endl;
		price(root,a,b);
		price(root1, a, b);
		price(root2, a, b);
		price(root3, a, b);
		price(root4, a, b);
		price(root5, a, b);
		price(root6, a, b);
	}
	template<typename A>
	void find_price(A a)
	{
		cout << endl << "Товары стоимостью  " << a << endl;
		price(root, a);
		price(root1, a);
		price(root2, a);
		price(root3, a);
		price(root4, a);
		price(root5, a);
		price(root6, a);
	}
	void showtree(string f) {
		cout << endl << "Лист товаров:" << endl;
			inorder(root, f);
			inorder(root1, f);
			inorder(root2, f);
			inorder(root3, f);
			inorder(root4, f);
			inorder(root5, f);
			inorder(root6, f);
	}
	void sort_price()
	{
		cout << endl << " Отсортированные цены: " << endl;
		int price_mass[1000];
		int id_mass[1000];
		string name_mass[1000];
		int counter = 0;
		counter=sorter(root,price_mass,id_mass,name_mass,counter);
		counter = sorter(root1, price_mass, id_mass, name_mass, counter);
		counter = sorter(root2, price_mass, id_mass, name_mass, counter);
		counter = sorter(root3, price_mass, id_mass, name_mass, counter);
		counter = sorter(root4, price_mass, id_mass, name_mass, counter);
		counter = sorter(root5, price_mass, id_mass, name_mass, counter);
		counter = sorter(root6, price_mass, id_mass, name_mass, counter);
		Shaker(price_mass, id_mass, name_mass, counter);
		for (int i = 0; i < counter; i++)
		{
			if(price_mass[i]>0)
			cout<<price_mass[i] << " Модель " << name_mass[i] << " ID " << id_mass[i] << endl;
		}

	}
	void find_device_class(string x)
	{
		cout << endl << " Товары выбранного поля : " << x<<endl;
		finder(root1, x);
		finder(root2, x);
		finder(root3, x);
		finder(root4, x);
		finder(root5, x);
		finder(root6, x);
	}
};
void create_Controlers(Controlers &name)
{
		ifstream input;
		char file_name[]("Controlers_input.txt");
	try{
		input.open(file_name);
		if (!input.is_open())
		{
			throw file_name;
		}
	}
	catch (char* file_name)
	{
		cout << "Невозможно открыть файл " << file_name<<" Ending..."; exit(1);
	}
	struct contr 
	{
		double d, data1, data2, data3;
		string Data, Data1;
		int DATA;
	};
	contr Contr;
	input >>Contr.d;
	input >> Contr.data1;
	input >> Contr.data2;
	input >> Contr.data3;
	input >> Contr.Data;
	input >> Contr.Data1;
	input >> Contr.DATA;
	name.create(Contr.d, Contr.data1, Contr.data2, Contr.data3, Contr.Data, Contr.Data1, Contr.DATA);
}
void create_Keybord(Keybord& name)
{
	ifstream input;
	char file_name[]("Keybord_input.txt");
	try {
		input.open(file_name);
		if (!input.is_open())
		{
			throw file_name;
		}
	}
	catch (char* file_name)
	{
		cout << "Невозможно открыть файл " << file_name << " Ending..."; exit(1);
	}
	struct keyb
	{
		double d, data1, data2, data3;
		string Data, Data1,Data2,Data3;
		int DATA,DATA1;
	};
	keyb Keyb;
	input >> Keyb.d;
	input >> Keyb.data1;
	input >> Keyb.data2;
	input >> Keyb.data3;
	input >> Keyb.DATA;
	input >> Keyb.Data;
	input >> Keyb.Data1;
	input >> Keyb.Data2;
	input >> Keyb.Data3;
	input >> Keyb.DATA1;
	name.create(Keyb.d, Keyb.data1, Keyb.data2, Keyb.data3, Keyb.DATA, Keyb.Data, Keyb.Data1, Keyb.Data2, Keyb.Data3, Keyb.DATA1);
}
void create_Mechanical(Mechanical& name)
{
	ifstream input;
	char file_name[]("Mechanical_input.txt");
	try {
		input.open(file_name);
		if (!input.is_open())
		{
			throw file_name;
		}
	}
	catch (char* file_name)
	{
		cout << "Невозможно открыть файл " << file_name << " Ending..."; exit(1);
	}
	struct mecha
	{
		double d, data1, data2, data3,data4;
		string Data, Data1, Data2, Data3,Data4,Data5;
		int DATA, DATA1,DATA2,DATA3;
	};
	mecha Mecha;
	input >> Mecha.d;
	input >> Mecha.data1;
	input >> Mecha.data2;
	input >> Mecha.data3; 
	input >> Mecha.DATA;
	input >> Mecha.Data;
	input >> Mecha.Data1;
	input >> Mecha.Data2;
	input >> Mecha.Data3;
	input >> Mecha.DATA1;
	input >> Mecha.Data4;
	input >> Mecha.Data5;
	input >> Mecha.data4;
	input >> Mecha.DATA2;
	input >> Mecha.DATA3;


	
	name.create(Mecha.d, Mecha.data1, Mecha.data2, Mecha.data3, Mecha.DATA, Mecha.Data, Mecha.Data1, Mecha.Data2, Mecha.Data3, Mecha.DATA1, Mecha.Data4, Mecha.Data5,Mecha.data4, Mecha.DATA2, Mecha.DATA3);
}
void create_Membran(Membran& name)
{
	ifstream input;
	char file_name[]("Membran_input.txt");
	try {
		input.open(file_name);
		if (!input.is_open())
		{
			throw file_name;
		}
	}
	catch (char* file_name)
	{
		cout << "Невозможно открыть файл " << file_name << " Ending..."; exit(1);
	}

	struct membr
	{
		double d, data1, data2, data3;
		string Data, Data1, Data2, Data3, Data4, Data5,Data6;
		int DATA, DATA1, DATA2;
	};
	membr Membr;
	input >> Membr.d;
	input >> Membr.data1;
	input >> Membr.data2;
	input >> Membr.data3;
	input >> Membr.DATA;
	input >> Membr.Data;
	input >> Membr.Data1;
	input >> Membr.Data2;
	input >> Membr.Data3;
	input >> Membr.DATA1;
	input >> Membr.Data4;
	input >> Membr.Data5;
	input >> Membr.Data6;
	input >> Membr.DATA2;
	name.create(Membr.d, Membr.data1, Membr.data2, Membr.data3, Membr.DATA, Membr.Data, Membr.Data1, Membr.Data2, Membr.Data3, Membr.DATA1, Membr.Data4, Membr.Data5,Membr.Data6, Membr.DATA2);
}
void create_Mouse(Mouse& name)
{
	ifstream input;
	char file_name[]("Mouse_input.txt");
	try {
		input.open(file_name);
		if (!input.is_open())
		{
			throw file_name;
		}
	}
	catch (char* file_name)
	{
		cout << "Невозможно открыть файл " << file_name << " Ending..."; exit(1);
	}
	struct mouse
	{
		double d, data1, data2, data3;
		string Data, Data1, Data2, Data3;
		int DATA, DATA1, DATA2;
	};
	mouse Mouse;
	input >> Mouse.d;
	input >> Mouse.data1;
	input >> Mouse.data2;
	input >> Mouse.data3;
	input >> Mouse.Data;
	input >> Mouse.Data1;
	input >> Mouse.Data2;
	input >> Mouse.Data3;
	input >> Mouse.DATA;
	input >> Mouse.DATA1;
	input >> Mouse.DATA2;
	name.create(Mouse.d, Mouse.data1, Mouse.data2, Mouse.data3, Mouse.Data, Mouse.Data1, Mouse.Data2, Mouse.Data3, Mouse.DATA,Mouse.DATA1, Mouse.DATA2);
}
void create_Optical(Optical& name)
{
	ifstream input;
	char file_name[]("Optical_input.txt");
	try {
		input.open(file_name);
		if (!input.is_open())
		{
			throw file_name;
		}
	}
	catch (char* file_name)
	{
		cout << "Невозможно открыть файл " << file_name << " Ending..."; exit(1);
	}
	struct optical
	{
		double d, data1, data2, data3;
		string Data, Data1, Data2, Data3, Data4, Data5, Data6;
		int DATA, DATA1, DATA2;
	};
	optical Optical;
	input >> Optical.d;
	input >> Optical.data1;
	input >> Optical.data2;
	input >> Optical.data3;
	input >> Optical.Data;
	input >> Optical.Data1;
	input >> Optical.Data2;
	input >> Optical.Data3;
	input >> Optical.Data4;
	input >> Optical.Data5;
	input >> Optical.Data6;
	input >> Optical.DATA;
	input >> Optical.DATA1;
	input >> Optical.DATA2;
	name.create(Optical.d, Optical.data1, Optical.data2, Optical.data3, Optical.Data, Optical.Data1, Optical.Data2, Optical.Data3, Optical.Data4, Optical.Data5, Optical.Data6, Optical.DATA, Optical.DATA1, Optical.DATA2);
}
void create_Trackball(Trackball& name)
{
	ifstream input;
	char file_name[]("Trackball_input.txt");
	try {
		input.open(file_name);
		if (!input.is_open())
		{
			throw file_name;
		}
	}
	catch (char* file_name)
	{
		cout << "Невозможно открыть файл " << file_name << " Ending..."; exit(1);
	}
	struct trackball
	{
		double d, data1, data2, data3;
		string Data, Data1, Data2, Data3, Data4, Data5, Data6;
		int DATA, DATA1, DATA2;
	};
	trackball Trackball;
	input >> Trackball.d;
	input >> Trackball.data1;
	input >> Trackball.data2;
	input >> Trackball.data3;
	input >> Trackball.Data;
	input >> Trackball.Data1;
	input >> Trackball.Data2;
	input >> Trackball.Data3;
	input >> Trackball.Data4;
	input >> Trackball.Data5;
	input >> Trackball.DATA;
	input >> Trackball.DATA1;
	input >> Trackball.DATA2;
	name.create(Trackball.d, Trackball.data1, Trackball.data2, Trackball.data3, Trackball.Data, Trackball.Data1, Trackball.Data2, Trackball.Data3, Trackball.Data4, Trackball.Data5, Trackball.DATA, Trackball.DATA1, Trackball.DATA2);
}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int counter = 0;
	Controlers s, s1, s2;
	Keybord k, k1, k2;
	Membran mem, mem1;
	Mechanical mech, mech1;
	Mouse mouse, mouse1;
	Optical mouse_opt, mouse_opt1;
	Trackball mouse_track, mouse_track1;
	s.create(10.0, 20.0, 30.0, 40.0, "Abysis", "Razer", 0);
	k.create(5, 6, 7, 8, 87, "mechanical", "russian", "AllowFPS", "HyperX", 11);
	mem.create(299, 136.7, 22, 400, 104, "Мембранная", "Русско-Английская", "Next HB-440", "Defender", 50000000, "Классическая", "Купольная", "Силикон", 11);
	mech.create(4263.83, 122, 10, 70, 87, "Механическая", "Русско-Английская", "K7", "MACHENIKE", 50000000, "Синие", "Тактильные", 2, 50, 9);
	mouse.create(2340, 10, 15, 200, "Mini Viper", "Razer", "Правая", "Оптическая", 1000, 8600, 222);
	mouse_opt.create(499, 22, 30, 86, "Scroll Too 200", "Genuis", "Правая", "Оптическая-Светодиодная", "Инфракрасный", "30 градусов", "KINGBRIGHT", 1000, 8600, 222);
	mouse_track.create(4799, 25, 27, 300, "Ergo M575", "Logitech", "Правая", "Трекбол", "Слева", "Небольшой", 1000, 10000, 333);
	create_Controlers(s1);
	create_Keybord(k1);
	create_Mechanical(mech1);
	create_Membran(mem1);
	create_Mouse(mouse1);
	create_Optical(mouse_opt1);
	create_Trackball(mouse_track1);
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	BTree bt;
	int n;
	n = s2.get_id();
	cout << " " << mem.get_price() << endl;
	bt.add_controler(n = s1.get_id(), s1);
	bt.add_controler(n = s.get_id(), s);
	k.set_id(1);
	bt.add_keybord(n = k.get_id(), k);
	bt.add_keybord(n = k1.get_id(), k1);
	mem.set_id(2);
	bt.add_membran(n = mem.get_id(), mem);
	bt.add_membran(n = mem1.get_id(), mem1);
	mech.set_id(3);
	bt.add_mechanical(n = mech.get_id(), mech);
	bt.add_mechanical(n = mech1.get_id(), mech1);
	mouse.set_id(4);
	bt.add_mouse(n = mouse.get_id(), mouse);
	bt.add_mouse(n = mouse1.get_id(), mouse1);
	mouse_opt.set_id(5);
	bt.add_optical(n = mouse_opt.get_id(), mouse_opt);
	bt.add_optical(n = mouse_opt1.get_id(), mouse_opt1);
	mouse_track.set_id(6);
	bt.add_trackball(n = mouse_track.get_id(), mouse_track);
	bt.add_trackball(n = mouse_track1.get_id(), mouse_track1);
	string f;
	bt.showtree(f);
	bt.find_price(4000,5000);
	bt.find_price(4263.83);
	bt.sort_price();
	bt.find_device_class("Mechanical keybord");
	system("pause");

}
