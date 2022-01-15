#pragma once
namespace Project1 {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections::Generic;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		ref class bbox
		{
		public:
				float x;
				float y;
				float w;
				float h;
				int cls;
				bbox(): x(0),y(0),w(0),h(0),cls(0){}
				bbox(String^ in) {
						auto sub = in->Split(' ');
						x = Double::Parse(sub[1]);
						y = Double::Parse(sub[2]);
						w = Double::Parse(sub[3]);
						h = Double::Parse(sub[4]);
						cls = Int32::Parse(sub[0]);
				}
				bbox(bbox% b ) {
						
						x =b.x;
						y = b.y;
						w = b.w;
						h = b.h;
						cls = b.cls;
				}
				void Input(String^ in) {
						auto sub=in->Split(' ');
						x= Double::Parse(sub[1]);
						y = Double::Parse(sub[2]);
						w = Double::Parse(sub[3]);
						h = Double::Parse(sub[4]);
						cls = Int32::Parse(sub[0]);
				}
				String^ GetString() {
						return  cls+ " " +x + " " + y + " " + w+ " " + h ;
				 }

		};

}

