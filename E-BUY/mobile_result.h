#pragma once
#include "mobile_final.h"
namespace EBUY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	/// <summary>
	/// Summary for mobile_result
	/// </summary>
	public ref class mobile_result : public System::Windows::Forms::Form
	{
	public:
		mobile_result(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		String^ set_name;
		String^ set_type;
		String^ str1;
		int count,set_price;
		array<String^ >^ str;
		array<Button^ >^ btn;
		array<TextBox^ >^ txt;
		Button^ button1 ;
		array<RadioButton^ >^ radio;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	public: 
	public: 
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	public: 

	public: 

	public: 
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mobile_result()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(210, 243);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Submit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &mobile_result::button2_Click);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(255, 196);
			this->flowLayoutPanel2->TabIndex = 1;
			this->flowLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mobile_result::flowLayoutPanel2_Paint);
			// 
			// mobile_result
			// 
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->button2);
			this->Name = L"mobile_result";
			this->Load += gcnew System::EventHandler(this, &mobile_result::mobile_result_Load_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void flowLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 
			 }
	public: System::Void mobile_result_Load(System::Object^  sender, System::EventArgs^  e) {
			//connect to mysql database
			String^ constring = L"datasource=127.0.0.1;port=3306;username=root;password=abc123"; 
			MySqlConnection^ conDatabase = gcnew MySqlConnection( constring ); 
			MySqlCommand^ cmd=gcnew MySqlCommand("select * from qwerty.mobiles where company = '"+set_name+"' and type = '"+set_type+"' and price < '"+10000*(set_price)+"';",conDatabase);
			MySqlDataReader^ myreader;
			try
			{
				conDatabase->Open();
				myreader=cmd->ExecuteReader();
				count = 0;
				while(myreader->Read())
				{
					count = count + 1;
					str1 = str[count]= myreader->GetString("setname");
					//textBox1->Text = str2;
				   /* button1 =  gcnew Button();
					TextBox^ box1 = gcnew TextBox();
					box1->Name = System::Convert::ToString(count);
					button1->Name = System::Convert::ToString(count);
					box1->Name = System::Convert::ToString(count);
					box1->Text = str1;
					box1->ReadOnly = true;*/
					btn[count]->Name = System::Convert::ToString(count);
					btn[count]->Text = "Check";
					txt[count]->Name = System::Convert::ToString(count);
					txt[count]->Text = str1;
					txt[count]->ReadOnly = true;
					/*button1->Text = "Check";
					
					button1->Click += gcnew System::EventHandler(this, &mobile_result::button1_Click);
					*/
					//btn[count]->Click += gcnew System::EventHandler(this, &mobile_result::button_click);
					//radios[i]->CheckedChanged += gcnew EventHandler(this, &mobile_result::radioCheckedChanged);
					//flowLayoutPanel1->Controls->Add(box1);
					//flowLayoutPanel1->Controls->Add(button1);
					flowLayoutPanel2->Controls->Add(txt[count]);
					flowLayoutPanel2->Controls->Add(btn[count]);
					flowLayoutPanel2->Controls->Add(radio[count]);
					//button1_Click();
				}
			}
			catch(Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}				 
			 }
	private: System::Void flowLayoutPanel1_Paint_1(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				// Button ^ button1 = ref new Button();
				// button1->Content = " ";
				// button1->Click(
			 }
	private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
			//	 String^ constring=L"datasource=localhost;port:3306;username=root;password=abc123";
			//MySqlConnection^ conDatabase=gcnew MySqlConnection(constring);
			 }
	/*public: System::Void button_Click(System::Object^  sender, System::EventArgs^  e) {
									mobile_final^ form = gcnew mobile_final;
									RadioButton^ rb = (RadioButton^ )sender;
									for(int i=1;i<=count;i++)
										if(rb->Checked = true)
										{
											break;
										}
									from->set_name = System::Convert::String(i);
									form->ShowDialog();
							 }*/
	
  private: System::Void mobile_result_Load_1(System::Object^  sender, System::EventArgs^  e) {
		   }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 int i;
			 for( i =0 ;i<=count;i++)
			 {
				if(radio[i]->Checked == true)
					break;
			 }
			 mobile_final^ form2 = gcnew mobile_final;
				 form2->set_name = System::Convert::ToString(i);;
				 //form2->set_name = "xyz";
				
				 form2->ShowDialog();
		 }

	/*public: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 mobile_final^ form2 = gcnew mobile_final;
				 form2->set_name = button1->Name;
				// form2->set_name = "xyz";
				
				 form2->ShowDialog();

			 }*/
private: System::Void flowLayoutPanel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}
