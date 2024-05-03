# CommentMaker
Uses llama3 and ollama to add comments to every files in the specified directory

## Installation

### Ollama and Llama3
https://ollama.com/download  
~~~
curl -fsSL https://ollama.com/install.sh | sh
ollama pull llama3
~~~


### Python : requests library
~~~
pip install requests
~~~



# Usage

There are two Python scripts to add comments to your code files :


## Segments.py

Segments.py sends a request every 100 rows (by default) to llama3. To use Segments.py, run the following command :
~~~
python Segments.py -i <input_path> -o <output_path> -p <prompt_header_path> -l <rows_per_requests>
~~~
- -i, --input_path: Path to the input file or directory containing the code to comment. If the file or directory does not exist, a warning will be displayed.  
- -o, --output_path: Path to the output directory where the commented code will be saved. If the directory does not exist, it will be created.
- -p, --prompt_header_path: Path to the prompt header file. If the file does not exist, a warning will be displayed.  
- -l, --rows-per-request: Number of rows to send in each request. Default is 100.

Or with the default values :  
~~~
python Segments.py
~~~
- input_path : ./files/  
- ouput_path : ./results/  
- prompt_header_path : ./prompt_header2.txt
- rows_per_request : 100  

## WholeFile.py

WholeFile.py sends a single request to llama3 for each file. To use WholeFile.py, run the following command :
~~~
python WholeFile.py -i <input_path> -o <output_path> -p <prompt_header_path>
~~~

- -i, --input_path: Path to the input file or directory containing the code to comment.  If the file or directory does not exist, a warning will be displayed. 
- -o, --output_path: Path to the output directory where the commented code will be saved. If the directory does not exist, it will be created.
- -p, --prompt_header_path: Path to the prompt header file. If the file does not exist, a warning will be displayed.  
  
Or with the default values :  
~~~
python WholeFile.py
~~~
- input_path : ./files/  
- ouput_path : ./results/  
- prompt_header_path : ./prompt_header2.txt
