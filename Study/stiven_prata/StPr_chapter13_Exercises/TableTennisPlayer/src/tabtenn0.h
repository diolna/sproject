#pragma once

class TableTennisPlayer {
public:
	TableTennisPlayer(const char* fn = "none ", const char * ln =  "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return hasTable;}
	void ResetTable(bool v) {hasTable = v;}
private:
	enum {LIM = 20};
	char firstname[LIM];
	char lastname[LIM];
	bool hasTable;

};

class RatedPlayer : public TableTennisPlayer {
public:
	RatedPlayer(unsigned int r = 0,  const char * fn = "none",
		const char* ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
	void ResetRating(unsigned int r) {rating = r;}
	unsigned int Rating() {return rating;}
private:
	unsigned int rating;
};
