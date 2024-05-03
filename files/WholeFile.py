import argparse
import requests
import json
import os

url = "http://localhost:11434/api/generate"
headers = {"Content-Type": "application/json"}



def call_LLM(prompt: str):
    data = {
        "model": "llama3",
        "prompt": prompt
    }

    response = requests.post(url, headers=headers, data=json.dumps(data))

    if response.status_code == 200:
        response_text = response.text.strip()
        json_objects = response_text.split('\n')
        json_objects = [obj for obj in json_objects if obj]

        responses_array = []
        for json_obj in json_objects:
            try:
                parsed_obj = json.loads(json_obj)
                responses_array.append(parsed_obj)
            except json.JSONDecodeError as e:
                print(f"Error parsing JSON object: {e}")

        #print("Responses Array:", responses_array)
        response_str = "".join([response["response"] for response in responses_array])
        return response_str
    else:
        print("Error:", response.status_code, response.text)



def process_file(file_path, prompt_header, result_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read().strip()
        temp_result = call_LLM(prompt_header+content).strip().split("FLAG")
        if len(temp_result)==1:
            result=temp_result[0]
        else:
            result=temp_result[1]
        with open(result_path, 'w', encoding='utf-8') as f:
            f.write(result)


#print(call_LLM("hello"))

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--prompt-header-path', default="./prompt_header2.txt", help='Path to the prompt header file')
    parser.add_argument('-i', '--input-path', default="./files/", help='Path to the directory containing the files to process')
    parser.add_argument('-r', '--result-path', default="./results/", help='Path to the directory where the results should be saved')
    args = parser.parse_args()

    input_path = args.input_path
    prompt_header_path = args.prompt_header_path
    results_path = args.result_path

    if not os.path.isdir(results_path):
        os.makedirs(results_path)
        print(f'Created output directory at {results_path}')

    if not os.path.isfile(prompt_header_path):
        print(f'Warning: Header file not found at {prompt_header_path}')
        return

    if not os.path.exists(input_path):
        print(f'Warning: Input directory/file not found at {input_path}')
        return

    prompt_header = ""
    with open(prompt_header_path, 'r', encoding='utf-8') as f:
        prompt_header = f.read()
    if os.path.isdir(input_path):
        files = [f for f in os.listdir(input_path) if os.path.isfile(os.path.join(input_path, f))]
    else:
        file_name = os.path.basename(input_path)
        input_path = os.path.dirname(input_path)
        files = [file_name]
    ignore_files = [".md", ".txt"]

    for file in files:
        if ("." not in file or any(s in file for s in ignore_files)): continue
        print(file)
        file_path = os.path.join(input_path, file)
        result_path_file = os.path.join(results_path, file)
        process_file(file_path, prompt_header, result_path_file)
        


if __name__ == '__main__':
    main()