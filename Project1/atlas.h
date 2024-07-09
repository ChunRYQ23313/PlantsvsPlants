#pragma once
#include<vector>
#include<graphics.h>

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	void load_from_file(LPCTSTR path_template, int num)
	{
		img_list.clear();
		img_list.resize(num);

		TCHAR path_file[256];
		for (int i = 0; i < num; i++)
		{
			_stprintf_s(path_file, path_template, i + 1);
			loadimage(&img_list[i], path_file);
		}
	}

	void clear()     //清空图集中已加载的图片对象
	{
		img_list.clear();
	}

	int get_size()   //获取图集中图片的数量
	{
		return (int)img_list.size();
	}

	IMAGE* get_image(int idx)  //
	{
		if (idx < 0 || idx >= img_list.size())
			return nullptr;

		return &img_list[idx];
	}

	void add_image(const IMAGE& img)
	{
		img_list.push_back(img);
	}


private:
	std::vector<IMAGE> img_list;
};