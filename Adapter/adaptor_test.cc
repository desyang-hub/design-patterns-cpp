#include "llm.h"
#include <iostream>

using namespace std;

void chat(const OpenAI& bot, const string& msg) {
    cout << bot.chat(msg) << endl;
}

int main() {

    OpenAI a;
    chat(a, "hai!");
    
    LLM llm;
    LLMAdaptor llm_adaptor = LLMAdaptor{llm};
    chat(llm_adaptor, "hai!");

    return 0;
}