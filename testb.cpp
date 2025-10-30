#include "fulgurance.h"   // your header defining Dataframe

int main(int argc, char** argv) {

    std::string file_name = "csv_test/Airline_Delay_Cause.csv";
    int runs = 5;

    Dataframe obj1;
    double total_time = 0.0;

    std::cout << "Benchmarking parser on file: " << file_name << "\n";
    std::cout << "Delimiter: ','  |  Quote: '\"'  |  Header: yes\n";
    std::cout << "----------------------------------------------------\n";

    for (int i = 1; i <= runs; ++i) {
        auto t0 = std::chrono::high_resolution_clock::now();
        obj1.readf(file_name, ',', true, '"');
        auto t1 = std::chrono::high_resolution_clock::now();

        double elapsed = std::chrono::duration<double>(t1 - t0).count();
        total_time += elapsed;
 
        std::cout << "Run " << i << ": " << elapsed << " s"
                  << " | nrows=" << obj1.get_nrow()
                  << " | ncols=" << obj1.get_ncol() << "\n";

        // Optional: reset between runs to avoid accumulation
        if (i < runs)
          obj1.reinitiate();  
    }

    double avg = total_time / runs;
    std::cout << "----------------------------------------------------\n";
    std::cout << "Average over " << runs << " runs: " << avg << " s\n";
    std::cout << "Rows: " << obj1.get_nrow() << "  |  Cols: " << obj1.get_ncol() << "\n";

    // Optional: throughput in MB/s
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    size_t file_size = file.tellg();
    std::cout << "Throughput: " << (file_size / avg / (1024.0 * 1024.0))
              << " MB/s\n";

    std::cout << "Head:\n";

    std::vector<int> rvec = {};
    for (size_t i = 0; i < 8; i += 1) {
      rvec.push_back(i);
    };

    std::vector<int> cvec = {0, 1, 5};

    obj1.display_filter_idx(rvec, cvec);

    const std::vector<char>& vectype = obj1.get_typecol();
    for (auto& el : vectype) {
      std::cout << el << " ";
    }

    std::cout << "\n";

    return 0;
}




