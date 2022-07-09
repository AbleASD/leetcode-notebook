#include "bits/stdc++.h"
using namespace std;

// Violent solution
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> us;
        vector<string> words;
        int maxLen = 0, minLen = INT_MAX;
        for (auto &root : dictionary)
        {
            us.emplace(root);
        }

        int n = sentence.size(), start = 0;

        while (start < n)
        {
            if (sentence[start] == ' ')
            {
                start++;
            }
            else
            {
                string word = parseWord(sentence, start);
                canRepalce(word, us);
                words.push_back(word);
            }
        }
        string ret;
        for (auto &word : words)
            ret += word + " ";
        ret.pop_back();
        return ret;
    }


    string parseWord(const string &sentence, int &start)
    {
        string ret;
        int n = sentence.size();
        while (start < n && sentence[start] != ' ')
        {
            ret += sentence[start++];
        }
        return ret;
    }


    void canRepalce(string &word, unordered_set<string> &us)
    {
        string ret = "";
        for (int i = 0; i < word.size(); ++i) {
            if (us.count(ret) != 0) {
                word = ret;
                return;
            }
            ret.push_back(word[i]);
        }
    }
};

int main()
{
    Solution slt;
    vector<string> dict = {"e", "k", "c", "harqp", "h", "gsafc", "vn", "lqp", "soy", "mr", "x", "iitgm", "sb", "oo", "spj", "gwmly", "iu", "z", "f", "ha", "vds", "v", "vpx", "fir", "t", "xo", "apifm", "tlznm", "kkv", "nxyud", "j", "qp", "omn", "zoxp", "mutu", "i", "nxth", "dwuer", "sadl", "pv", "w", "mding", "mubem", "xsmwc", "vl", "farov", "twfmq", "ljhmr", "q", "bbzs", "kd", "kwc", "a", "buq", "sm", "yi", "nypa", "xwz", "si", "amqx", "iy", "eb", "qvgt", "twy", "rf", "dc", "utt", "mxjfu", "hm", "trz", "lzh", "lref", "qbx", "fmemr", "gil", "go", "qggh", "uud", "trnhf", "gels", "dfdq", "qzkx", "qxw"};
    string sentence = "ikkbp miszkays wqjferqoxjwvbieyk gvcfldkiavww vhokchxz dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dco kddxmckhvqifbuzkhstp wc ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy ifvifheoxqlbosfww mengfdydekwttkhbzenk wjhmmyltmeufqvcpcxg hthcuovils ldipovluo aiprogn nusquzpmnogtjkklfhta klxvvlvyh nxzgnrveghc mpppfhzjkbucv cqcft uwmahhqradjtf iaaasabqqzmbcig zcpvpyypsmodtoiif qjuiqtfhzcpnmtk yzfragcextvx ivnvgkaqs iplazv jurtsyh gzixfeugj rnukjgtjpim hscyhgoru aledyrmzwhsz xbahcwfwm hzd ygelddphxnbh rvjxtlqfnlmwdoezh zawfkko iwhkcddxgpqtdrjrcv bbfj mhs nenrqfkbf spfpazr wrkjiwyf cw dtd cqibzmuuhukwylrnld dtaxhddidfwqs bgnnoxgyynol hg dijhrrpnwjlju muzzrrsypzgwvblf zbugltrnyzbg hktdviastoireyiqf qvufxgcixvhrjqtna ipfzhuvgo daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh qzsaobsghgm ichlpsjlsrwzhbyfhm ksenb bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala qmxixtooxtbrzyorn gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn frotscysdyclrc ckcttaceuuxzcghw pxbd oklwhcppuziixpvihihp";
    slt.replaceWords(dict, sentence);
    return 0;
}