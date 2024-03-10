import pikepdf          # Install this using pip if not already installed

pdf_loc = input("PDF location: ") 	# Example: C:\\Users\\Desktop\\file1.pdf
pdf_pass = input("PDF password: ")	# Example: pass1

pdf = pikepdf.open(pdf_loc, password=pdf_pass)

print("\nProcessing...\n")

pdf_save = input("Save file as: ")	# Example: new_file1.pdf
pdf_loc2 = input("Save location: ")	# Example: C:\\Users\\Desktop

pdf.save(pdf_loc2 + '\\' + pdf_save)

print("The password successfully removed from the PDF")
print("\aLocation: " + pdf_loc + '\\' + pdf_save)
