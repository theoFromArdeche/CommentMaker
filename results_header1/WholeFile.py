


// This function makes a POST request to the specified URL with JSON data and returns the response as a string.
def call_LLM(prompt: str):


// This function processes a file by calling the LLM function on its contents, splitting the result at the "FLAG" marker, and writing the appropriate part to a new file.
def process_file(file_path, prompt_header, result_path):


// This is the main entry point of the application. It parses command-line arguments, sets up the output directory, reads the prompt header, processes files in the input directory, and writes results to the output directory.
def main():