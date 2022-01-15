#pragma once
#include"MyImage.h"
#include"bbox.h"
namespace Project1 {

		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections::Generic;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;


		/// <summary>
		/// MyForm 的摘要
		/// </summary>
		public ref class MyForm : public System::Windows::Forms::Form
		{
		public:
				MyForm(void)
				{
						InitializeComponent();
						//
						//TODO:  在此加入建構函式程式碼
						//
				}

		protected:
				/// <summary>
				/// 清除任何使用中的資源。
				/// </summary>
				~MyForm()
				{
						if (components)
						{
								delete components;
						}
				}
		private: System::Windows::Forms::PictureBox^  pictureBox1;
				 Point ptFromH;
				 Point ptToH;
				 Point ptFromV;
				 Point ptToV;
				 bool isInPic = false;
				 String^ img_dir;
				 String^ class_path;
				 //static array<String^>^ file_array;
				 int file_array_idx;
				 List<String^> file_array;
				 List<MyImage^>img_array;
				 bbox box;
				 bool isFirstClick = true;
				 Point mouse_pos, b1, b2;
				 List<Pen^> colors;
				 Pen^ cur_pen;
		private: System::Windows::Forms::Button^  open_file_btn;
		private: System::Windows::Forms::FolderBrowserDialog^  open_file_dlg;
		private: System::Windows::Forms::Label^  img_lbl;
		private: System::Windows::Forms::HScrollBar^  img_sb;


		private: System::Windows::Forms::Button^  class_btn;
		private: System::Windows::Forms::OpenFileDialog^  class_dlg;
		private: System::Windows::Forms::ListBox^  class_lb;
		private: System::Windows::Forms::CheckBox^  show_class_cb;

		protected:

		private:
				/// <summary>
				/// 設計工具所需的變數。
				/// </summary>
				System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
				/// <summary>
				/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
				/// 這個方法的內容。
				/// </summary>
				void InitializeComponent(void)
				{
						this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
						this->open_file_btn = (gcnew System::Windows::Forms::Button());
						this->open_file_dlg = (gcnew System::Windows::Forms::FolderBrowserDialog());
						this->img_lbl = (gcnew System::Windows::Forms::Label());
						this->img_sb = (gcnew System::Windows::Forms::HScrollBar());
						this->class_btn = (gcnew System::Windows::Forms::Button());
						this->class_dlg = (gcnew System::Windows::Forms::OpenFileDialog());
						this->class_lb = (gcnew System::Windows::Forms::ListBox());
						this->show_class_cb = (gcnew System::Windows::Forms::CheckBox());
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
						this->SuspendLayout();
						// 
						// pictureBox1
						// 
						this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
								| System::Windows::Forms::AnchorStyles::Left)
								| System::Windows::Forms::AnchorStyles::Right));
						this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
						this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
						this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
						this->pictureBox1->Location = System::Drawing::Point(12, 12);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->Size = System::Drawing::Size(1200, 675);
						this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
						this->pictureBox1->TabIndex = 0;
						this->pictureBox1->TabStop = false;
						this->pictureBox1->Visible = false;
						this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
						this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseEnter);
						this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);
						this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
						// 
						// open_file_btn
						// 
						this->open_file_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
								| System::Windows::Forms::AnchorStyles::Left)
								| System::Windows::Forms::AnchorStyles::Right));
						this->open_file_btn->Cursor = System::Windows::Forms::Cursors::Hand;
						this->open_file_btn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
								static_cast<System::Byte>(0)));
						this->open_file_btn->Location = System::Drawing::Point(12, 780);
						this->open_file_btn->Name = L"open_file_btn";
						this->open_file_btn->Size = System::Drawing::Size(388, 69);
						this->open_file_btn->TabIndex = 1;
						this->open_file_btn->Text = L"Open Image Directory";
						this->open_file_btn->UseVisualStyleBackColor = true;
						this->open_file_btn->Visible = false;
						this->open_file_btn->Click += gcnew System::EventHandler(this, &MyForm::open_file_btn_Click);
						// 
						// open_file_dlg
						// 
						this->open_file_dlg->SelectedPath = L"D:\\nckuWork\\1092同步\\1101\\OOP\\imgdir";
						this->open_file_dlg->ShowNewFolderButton = false;
						// 
						// img_lbl
						// 
						this->img_lbl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
								| System::Windows::Forms::AnchorStyles::Left)
								| System::Windows::Forms::AnchorStyles::Right));
						this->img_lbl->AutoSize = true;
						this->img_lbl->Location = System::Drawing::Point(21, 749);
						this->img_lbl->Name = L"img_lbl";
						this->img_lbl->Size = System::Drawing::Size(14, 12);
						this->img_lbl->TabIndex = 2;
						this->img_lbl->Text = L"   ";
						// 
						// img_sb
						// 
						this->img_sb->LargeChange = 1;
						this->img_sb->Location = System::Drawing::Point(12, 707);
						this->img_sb->Name = L"img_sb";
						this->img_sb->Size = System::Drawing::Size(1200, 18);
						this->img_sb->TabIndex = 3;
						this->img_sb->Visible = false;
						this->img_sb->ValueChanged += gcnew System::EventHandler(this, &MyForm::img_sb_ValueChanged);
						// 
						// class_btn
						// 
						this->class_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
								| System::Windows::Forms::AnchorStyles::Left)
								| System::Windows::Forms::AnchorStyles::Right));
						this->class_btn->Cursor = System::Windows::Forms::Cursors::Hand;
						this->class_btn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
								static_cast<System::Byte>(0)));
						this->class_btn->Location = System::Drawing::Point(434, 780);
						this->class_btn->Name = L"class_btn";
						this->class_btn->Size = System::Drawing::Size(388, 69);
						this->class_btn->TabIndex = 5;
						this->class_btn->Text = L"Open Class Name File";
						this->class_btn->UseVisualStyleBackColor = true;
						this->class_btn->Click += gcnew System::EventHandler(this, &MyForm::class_btn_Click);
						// 
						// class_lb
						// 
						this->class_lb->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
								static_cast<System::Byte>(0)));
						this->class_lb->FormattingEnabled = true;
						this->class_lb->ItemHeight = 24;
						this->class_lb->Location = System::Drawing::Point(1257, 28);
						this->class_lb->Name = L"class_lb";
						this->class_lb->Size = System::Drawing::Size(273, 220);
						this->class_lb->TabIndex = 7;
						this->class_lb->Visible = false;
						this->class_lb->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::class_lb_SelectedIndexChanged);
						// 
						// show_class_cb
						// 
						this->show_class_cb->AutoSize = true;
						this->show_class_cb->Checked = true;
						this->show_class_cb->CheckState = System::Windows::Forms::CheckState::Checked;
						this->show_class_cb->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
								static_cast<System::Byte>(0)));
						this->show_class_cb->Location = System::Drawing::Point(1276, 268);
						this->show_class_cb->Name = L"show_class_cb";
						this->show_class_cb->Size = System::Drawing::Size(218, 28);
						this->show_class_cb->TabIndex = 8;
						this->show_class_cb->Text = L"Show Class on Image";
						this->show_class_cb->UseVisualStyleBackColor = true;
						this->show_class_cb->Visible = false;
						this->show_class_cb->CheckedChanged += gcnew System::EventHandler(this, &MyForm::show_class_cb_CheckedChanged);
						// 
						// MyForm
						// 
						this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
						this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
						this->ClientSize = System::Drawing::Size(1584, 861);
						this->Controls->Add(this->show_class_cb);
						this->Controls->Add(this->class_lb);
						this->Controls->Add(this->class_btn);
						this->Controls->Add(this->img_sb);
						this->Controls->Add(this->img_lbl);
						this->Controls->Add(this->open_file_btn);
						this->Controls->Add(this->pictureBox1);
						this->Name = L"MyForm";
						this->Text = L"MyForm";
						this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
						this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
						this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
						this->MouseLeave += gcnew System::EventHandler(this, &MyForm::MyForm_MouseLeave);
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
						this->ResumeLayout(false);
						this->PerformLayout();

				}
#pragma endregion

		private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {

		}
		private: System::Void pictureBox1_MouseHover(System::Object^  sender, System::EventArgs^  e) {

		}
		private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				if (isInPic) {
						// Draw a line in the PictureBox.
						e->Graphics->DrawLine(System::Drawing::Pens::Red, ptFromH.X, ptFromH.Y, ptToH.X, ptToH.Y);
						e->Graphics->DrawLine(System::Drawing::Pens::Red, ptFromV.X, ptFromV.Y, ptToV.X, ptToV.Y);
				}
				if (img_array[file_array_idx]->GetBBoxes().Count != 0) {
						for each  (bbox^ box in img_array[file_array_idx]->GetBBoxes())
						{

								float w = (float)pictureBox1->Width*box->w;
								float h = (float)pictureBox1->Height*box->h;
								float x = (float)pictureBox1->Width*box->x - w / 2.0;
								float y = (float)pictureBox1->Height*box->y - h / 2.0;
								String^ cls_name = class_lb->GetItemText(class_lb->Items[box->cls]);

								e->Graphics->DrawRectangle(colors[box->cls%colors.Count], x, y, w, h);
								if (show_class_cb->Checked)
								{
										e->Graphics->FillRectangle(Brushes::White, x, y, (float)cls_name->Length * 8, 16.0);
										e->Graphics->DrawString(cls_name,
												%Drawing::Font("Times New Roman", 12),
												%Drawing::SolidBrush(Color::Black), x, y);
								}

						}
				}
				if (!isFirstClick) {
						b2 = mouse_pos;
						float x = Math::Min((float)b1.X, (float)b2.X);
						float y = Math::Min((float)b1.Y, (float)b2.Y);
						float w = (float)Math::Abs(b1.X - b2.X);
						float h = (float)Math::Abs(b1.Y - b2.Y);
						e->Graphics->DrawRectangle(cur_pen, x, y, w, h);
				}
		}


		private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				ptFromH = Point(0, e->Y);
				ptToH = Point(pictureBox1->Right, e->Y);
				ptFromV = Point(e->X, 0);
				ptToV = Point(e->X, pictureBox1->Bottom);
				mouse_pos = e->Location;
				pictureBox1->Invalidate();
		}
		private: System::Void MyForm_MouseLeave(System::Object^  sender, System::EventArgs^  e) {

		}
		private: System::Void pictureBox1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				isInPic = true;
		}
		private: System::Void pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				isInPic = false;
				pictureBox1->Invalidate();
		}
		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				colors.Add(Pens::Orange);
				colors.Add(Pens::Yellow);
				colors.Add(Pens::Green);
				colors.Add(Pens::Blue);
				colors.Add(Pens::DarkBlue);
				colors.Add(Pens::Violet);
		}

		private: System::Void open_file_btn_Click(System::Object^  sender, System::EventArgs^  e) {
				if (open_file_dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
						img_dir = open_file_dlg->SelectedPath;

						// array<String^>^ temp_array =;
						for each(String^ item in  System::IO::Directory::GetFiles(img_dir))
						{
								if (item->EndsWith(".jpg")) {

										file_array.Add(item);

										img_array.Add(gcnew MyImage(item));
								}
						}

						if (file_array.Count != 0) {
								file_array_idx = 0;
								img_lbl->Text = img_array[file_array_idx]->GetLabelName();

								pictureBox1->Image = Image::FromFile(img_array[file_array_idx]->GetFileName());
						}
						else return;
						open_file_btn->Enabled = false;
						this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
						this->pictureBox1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseWheel);
						pictureBox1->Visible = true;
						img_sb->Visible = true;
						show_class_cb->Visible = true;
						img_sb->Maximum = file_array.Count - 1;
						img_sb->Minimum = 0;
						img_sb->Value = file_array_idx;
						return;
				}
				else return;

		}

		private: System::Void pictureBox1_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				isFirstClick = true;
				if (e->Delta < 0 && file_array_idx < file_array.Count - 1) {
						img_sb->Value++;
				}
				else if (e->Delta > 0 && file_array_idx > 0) {
						img_sb->Value--;
				}
		}

		private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				switch (e->Button)
				{
				case System::Windows::Forms::MouseButtons::Left:
						if (isFirstClick) {
								b1 = mouse_pos;
						}
						else {
								b2 = mouse_pos;
								box.x = ((float)b1.X + (float)b2.X) / 2.0 / (float)pictureBox1->Width;
								box.y = ((float)b1.Y + (float)b2.Y) / 2.0 / (float)pictureBox1->Height;
								box.w = (float)Math::Abs(b1.X - b2.X) / (float)pictureBox1->Width;
								box.h = (float)Math::Abs(b1.Y - b2.Y) / (float)pictureBox1->Height;
								box.cls = class_lb->SelectedIndex;
								img_array[file_array_idx]->AddBBox(box);
								
						}
						isFirstClick = !isFirstClick;
						break;
				case System::Windows::Forms::MouseButtons::Right:
						if (isFirstClick) {
								img_array[file_array_idx]->RemoveBBoxAtPoint((float)e->X / (float)pictureBox1->Width,
								(float)e->Y / (float)pictureBox1->Height);
								
						}
								

						isFirstClick = true;
						break;
				default:
						break;
				}

		}


		private: System::Void img_sb_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				if (img_sb->Value > file_array_idx) {
						img_array[file_array_idx]->UpdateLabel();
						file_array_idx = img_sb->Value;
						img_lbl->Text = img_array[file_array_idx]->GetLabelName();
						pictureBox1->Image = Image::FromFile(img_array[file_array_idx]->GetFileName());
				}
				else if (img_sb->Value < file_array_idx) {
						img_array[file_array_idx]->UpdateLabel();
						file_array_idx = img_sb->Value;
						img_lbl->Text = img_array[file_array_idx]->GetLabelName();
						pictureBox1->Image = Image::FromFile(img_array[file_array_idx]->GetFileName());
				}
		}

		private: System::Void class_lb_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				cur_pen = colors[class_lb->SelectedIndex%colors.Count];
				pictureBox1->Invalidate();
		}
		private: System::Void class_btn_Click(System::Object^  sender, System::EventArgs^  e) {
				if (class_dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
						class_path = class_dlg->FileName;
						if (File::Exists(class_path)) {
								StreamReader^ sr = File::OpenText(class_path);
								String^ str;
								int cnt = 0;
								while ((str = sr->ReadLine()) != nullptr)
								{
										class_lb->Items->Add(cnt + ": " + str);
										cnt++;
								}
								sr->Close();
						}
						class_lb->Visible = true;
						class_btn->Enabled = false;
						class_lb->SelectedIndex = 0;
						cur_pen = Pens::Orange;
						open_file_btn->Visible = true;
				}
		}
		private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				//class_lb->SelectedValue = 0;
		}
		private: System::Void show_class_cb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				pictureBox1->Invalidate();
				class_lb->Focus();
		}
		private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				if (img_array.Count != 0)
						img_array[file_array_idx]->UpdateLabel();

		}
		};
}



