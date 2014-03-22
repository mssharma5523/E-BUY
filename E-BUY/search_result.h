#pragma once

namespace EBUY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for search_result
	/// </summary>
	public ref class search_result : public System::Windows::Forms::Form
	{
	public:
		search_result(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		String^ str1;
		String^ str;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~search_result()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(248, 226);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// search_result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"search_result";
			this->Text = L"search_result";
			this->Load += gcnew System::EventHandler(this, &search_result::search_result_Load);
			this->ResumeLayout(false);
			//
			//strings
			//
			this->str1 ="";
			this->str ="";
		}
#pragma endregion
	private: System::Void search_result_Load(System::Object^  sender, System::EventArgs^  e) {
				 
			//code for search properties 
			//connect to mysql database
			String^ constring = L"datasource=127.0.0.1;port=3306;username=root;password=abc123"; 
			MySqlConnection^ conDatabase = gcnew MySqlConnection( constring ); 
			
			if(String::Compare(str,"Mobiles") == 0)
			{
				//search in mobile table
				MySqlCommand^ cmd=gcnew MySqlCommand("select * from qwerty.mobiles where setname = '"+str1->ToLower()+"' or setname = '"+str1+"' or setname ='"+str1->ToLower()+"' or company = '"+str1+"';",conDatabase);
				MySqlDataReader^ myreader;
			try
			{
				conDatabase->Open();
				myreader=cmd->ExecuteReader();
				int count = 0;
				while(myreader->Read())
				{
					count = count + 1;
					str= myreader->GetString("setname");
					//textBox1->Text = str2;
					Button^ button1 =  gcnew Button();
					TextBox^ box1 = gcnew TextBox();
					//box1->Name = count;
					//button->Name = count;
					box1->Text = str;
					box1->ReadOnly = true;
					button1->Text = "Check";
					//button1->Click += gcnew System::EventHandler(this, &search_result::button1_Click);

					flowLayoutPanel1->Controls->Add(box1);
					flowLayoutPanel1->Controls->Add(button1);
					//button1_Click();
				}
			}
			catch(Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}				 
			}
			else if(String::Compare(str,"TV") == 0)
			{
				//compare in tv table
				MySqlCommand^ cmd=gcnew MySqlCommand("select * from qwerty.mobiles where setname = '"+str1->ToLower()+"' or setname = '"+str1+"' or setname ='"+str1->ToLower()+"' or company = '"+str1+"';",conDatabase);
			}
			else if(String::Compare(str,"Laptop") == 0)
			{
				//search in laptop
				MySqlCommand^ cmd=gcnew MySqlCommand("select * from qwerty.laptop where setname = '"+str1->ToLower()+"' or setname = '"+str+"' or setname ='"+str1->ToLower()+"' or company = '"+str1+"';",conDatabase);
			}
			else if(String::Compare(str,"Books") == 0)
			{
				MySqlCommand^ cmd=gcnew MySqlCommand("select * from qwerty.books where setname = '"+str1->ToLower()+"' or setname = '"+str1+"' or setname ='"+str1->ToLower()+"' or company = '"+str1+"';",conDatabase);
			}
			else if(String::Compare(str,"Media") == 0)
			{
				MySqlCommand^ cmd=gcnew MySqlCommand("select * from qwerty.media where setname = '"+str1->ToLower()+"' or setname = '"+str1+"' or setname ='"+str1->ToLower()+"' or company = '"+str1+"';",conDatabase);
			}
			else if(String::Compare(str,"Sports") == 0)
			{
				MySqlCommand^ cmd=gcnew MySqlCommand("select * from qwerty.sports where setname = '"+str1->ToLower()+"' or setname = '"+str1+"' or setname ='"+str1->ToLower()+"' or company = '"+str1+"';",conDatabase);
			}
			else if(String::Compare(str,"Clothes") == 0)
			{
				MySqlCommand^ cmd=gcnew MySqlCommand("select * from qwerty.clothes where setname = '"+str1->ToLower()+"' or setname = '"+str1+"' or setname ='"+str1->ToLower()+"' or company = '"+str1+"';",conDatabase);
			}
			else
			{
				MessageBox::Show("Please select the correct option");
			}
			
		}
			 
	};
}
