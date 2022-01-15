#pragma once
#include"bbox.h"
namespace Project1 {
		using namespace System;
		using namespace System::IO;
		using namespace System::ComponentModel;
		using namespace System::Collections::Generic;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		ref class MyImage
		{
		private:
				String^Label_Name;
				String^ File_Name;
				List<bbox^> bboxes;
		public:
				MyImage(String^ img_name) {
						
						Label_Name =gcnew  String(img_name->Replace(".jpg",".txt"));
						File_Name = gcnew String(img_name);
						if (File::Exists(Label_Name)) {
								StreamReader^ sr = File::OpenText(Label_Name);
								String^ str;
								while ((str = sr->ReadLine()) != nullptr)
								{
										bboxes.Add(gcnew bbox(str));
								}
								sr->Close();
						}
						
				}
				String^ GetFileName() {
						return File_Name;
				}
				String^ GetLabelName() {
						return Label_Name;
				}
				List<bbox^>% GetBBoxes() {
						return bboxes;
				}
				void AddBBox(bbox% b) {
						bboxes.Add(gcnew bbox(b));
				}
				void RemoveBBox(bbox% b) {
						bboxes.Remove(%b);
				}
				void RemoveBBoxAtPoint(float x, float y) {
						for (int i=bboxes.Count-1; i >=0; i--) {
								float x1 = bboxes[i]->x - bboxes[i]->w / 2.0;
								float x2 = bboxes[i]->x + bboxes[i]->w / 2.0;
								float y1 = bboxes[i]->y - bboxes[i]->h / 2.0;
								float y2 = bboxes[i]->y + bboxes[i]->h / 2.0;
								if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
										bboxes.Remove(bboxes[i]);
										break;
								}
						}
				}
				void UpdateLabel() {
						if (bboxes.Count != 0) {
								StreamWriter^ sw = gcnew StreamWriter(Label_Name);
								for (int i=0; i < bboxes.Count; i++) {
										sw->WriteLine(bboxes[i]->GetString());
								}
								sw->Close();
						}
						else {
								File::Delete(Label_Name);
						}
						
				}




		};
		


}

