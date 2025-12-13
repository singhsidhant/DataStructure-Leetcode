#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>

class Solution {
private:
    std::map<std::string, int> order = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}
    };

    struct CouponData {
        std::string c;
        std::string b;
    };

    bool codeValid(const std::string& s) {
        if (s.empty()) return false;
        for (char ch : s) {
            if (!std::isalnum(static_cast<unsigned char>(ch)) && ch != '_') {
                return false;
            }
        }
        return true;
    }

    bool compareCouponsHelper(const CouponData& a, const CouponData& b) const {
        if (order.at(a.b) != order.at(b.b)) {
            return order.at(a.b) < order.at(b.b);
        }
        return a.c < b.c;
    }

public:
    std::vector<std::string> validateCoupons(std::vector<std::string>& code, std::vector<std::string>& businessLine, std::vector<bool>& isActive) {
        int n = code.size();
        std::vector<CouponData> valid;

        for (int i = 0; i < n; ++i) {
            if (isActive[i]) {
                if (businessLine[i] == "electronics" || 
                    businessLine[i] == "grocery" || 
                    businessLine[i] == "pharmacy" || 
                    businessLine[i] == "restaurant") {
                    
                    if (codeValid(code[i])) {
                        valid.push_back({code[i], businessLine[i]});
                    }
                }
            }
        }

        std::sort(valid.begin(), valid.end(), 
            [this](const CouponData& a, const CouponData& b) {
                return compareCouponsHelper(a, b);
            });

        std::vector<std::string> result;
        for (const auto& item : valid) {
            result.push_back(item.c);
        }

        return result;
    }
};