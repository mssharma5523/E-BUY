#pragma once

namespace EBUY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mobile_final
	/// </summary>
	public ref class mobile_final : public System::Windows::Forms::Form
	{
	public:
		mobile_final(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		String^ set_name;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mobile_final()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
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
			this->SuspendLayout();
			// 
			// mobile_final
			// 
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"mobile_final";
			this->Load += gcnew System::EventHandler(this, &mobile_final::mobile_final_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 
			 }
	private: System::Void mobile_final_Load(System::Object^  sender, System::EventArgs^  e) {
				 textBox1->Text = set_name;
			 }
	
	};
}
