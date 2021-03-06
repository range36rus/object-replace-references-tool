// object_replace_references_tool.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "scene_objects.h"
int main(int argc, char* argv[])
{
	Locale lc(1251);

	// информация
	// массовая замена ссылок на файлы объектов на другие(применялось в случае, если автоматический патчер лодов не нашел замены файлу, хотя замена есть(микроразличия))

	scene_object obj(R"(levels\in\scene_object.part)");
	if (!obj.init(argc, argv))
	{
		system("pause");
		return 0;
	}
	if (!obj.loadSceneObject())
	{
		system("pause");
		return 0;
	}
	if (!obj.loadSectionReplace(R"(levels\references_replace\references.txt)"))
	{
		system("pause");
		return 0;
	}
	obj.runReplace();
	if (!obj.writeNewSceneObject(R"(levels\out\scene_object.part)"))
	{
		system("pause");
		return 0;
	}

	std::cout << "Ссылки в входном файле успешно заменены." << std::endl;
	system("pause");
	return 0;
}

