#include "Strings.h"

using Entry = pair<string, int>;
using Entries = vector<Entry>;

/**
 * Find the 'k' most frequently occurring strings in some text,
 * along with their counts.
 */
class TopKStrings {
    struct GreaterThan {
        bool operator()(const Entry& lhs, const Entry& rhs) {
            return lhs.second > rhs.second;
        }
    };
    using Tally = unordered_map<string, int>;
    using MinHeap = priority_queue<Entry, vector<Entry>, GreaterThan>;

private:
    vector<string> v_;
    int k_;
    Tally tally_;
    MinHeap minHeap_;
    Entries results_;

public:
    TopKStrings(const vector<string>& v, int k) :
        v_(v), k_(k), results_(k) {}

    vector<Entry> solve() {
        doTally();
        buildMinHeap();
        extractResults();
        return results_;
    }

private:
    void doTally() {
        for (auto& word : v_) {
            ++tally_[word];
        }
    }

    void buildMinHeap() {
        int min = -1;
        for (auto& entry : tally_) {
            if (entry.second > min) {
                minHeap_.push(entry);
                while ((int)minHeap_.size() > k_) {
                    minHeap_.pop();
                }
                min = minHeap_.top().second;
            }
        }
    }

    void extractResults() {
        for (int i = results_.size() - 1; i >= 0; --i) {
            results_[i] = minHeap_.top();
            minHeap_.pop();
        }
    }
};

void testTopKStrings() {
    cout << endl;
    cout << "Test topKStrings():" << endl;
    cout << "===================" << endl;

    string text =
        "four score and seven years ago our fathers brought "
        "forth on this continent a new nation conceived in "
        "liberty and dedicated to the proposition that all "
        "men are created equal now we are engaged in a great "
        "civil war testing whether that nation or any nation "
        "so conceived and so dedicated can long endure we are "
        "met on a great battlefield of that war we have come "
        "to dedicate a portion of that field as a final resting "
        "place for those who here gave their lives that that "
        "nation might live it is altogether fitting and proper "
        "that we should do this but in a larger sense we can "
        "not dedicate we can not consecrate we can not hallow "
        "this ground the brave men living and dead who struggled "
        "here have consecrated it far above our poor power to "
        "add or detract the world will little note nor long "
        "remember what we say here but it can never forget what "
        "they did here it is for us the living rather to be "
        "dedicated here to the unfinished work which they who "
        "fought here have thus far so nobly advanced it is "
        "rather for us to be here dedicated to the great task "
        "remaining before us that from these honored dead we "
        "take increased devotion to that cause for which they "
        "gave the last full measure of devotion that we here "
        "highly resolve that these dead shall not have died in "
        "vain that this nation under god shall have a new birth "
        "of freedom and that government of the people by the "
        "people for the people shall not perish from the earth";

    istringstream iss(text);
    string word;
    vector<string> v;
    while (iss >> word) {
        v.push_back(word);
    }
    TopKStrings topKStrings(v, 10);
    vector<Entry> topTen = topKStrings.solve();

    cout << "Top 10 words in Gettysburg Address:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i + 1 << ". " << topTen[i].first << "\t("
             << topTen[i].second << " occurrences)" << endl;
    }
}
