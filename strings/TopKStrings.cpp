#include "Strings.h"

using Entry = pair<string, int>;

struct GreaterThan {
    bool operator()(const Entry& lhs, const Entry& rhs) {
        return lhs.second > rhs.second;
    }
};

using Tally = unordered_map<string, int>;
using TallyIterator = Tally::const_iterator;
using MinHeap = priority_queue<Entry, vector<Entry>, GreaterThan>;

static Tally tallyStrings(const vector<string>& v);
static MinHeap buildMinHeap(const Tally& tally, int k);
static vector<Entry> extractResults(MinHeap& heap);

/**
 * @brief Find the |k| most frequently occurring strings in some text.
 *
 * @param v The text of interest.
 * @param k Specifies the |k| in "|k| most frequently occurring".
 * @return The |k| most frequently occurring strings, and their counts.
 */
vector<Entry> topKStrings(const vector<string>& v, int k) {
    Tally tally = tallyStrings(v);
    MinHeap heap = buildMinHeap(tally, k);
    return extractResults(heap);
}

static Tally tallyStrings(const vector<string>& v) {
    Tally tally;
    for (const auto& s : v) {
        ++tally[s];
    }
    return tally;
}

static MinHeap buildMinHeap(const Tally& tally, int k) {
    MinHeap minHeap;
    int count = 0;
    int min = -1;
    TallyIterator iter = tally.cbegin();
    while (iter != tally.end()) {
        Entry entry = *iter++;
        if (entry.second > min) {
            minHeap.push(entry);
            ++count;
            if (count > k) {
                minHeap.pop();
                min = minHeap.top().second;
                --count;
            }
        }
    }
    return minHeap;
}

static vector<Entry> extractResults(MinHeap& heap) {
    vector<Entry> entries(heap.size());
    for (int i = heap.size() - 1; i >= 0; --i) {
        entries[i] = heap.top();
        heap.pop();
    }
    return entries;
}

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
    vector<Entry> topTen = topKStrings(v, 10);

    cout << "Top 10 words in Gettysburg Address:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i + 1 << ". " << topTen[i].first << "\t("
             << topTen[i].second << " occurrences)" << endl;
    }
}
