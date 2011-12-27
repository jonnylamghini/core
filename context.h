// The core library - copyright GarageGames.  The core library is released under the MIT Open Source software license.  See /license.txt in this distribution for specific license terms.

struct context
{
	public:
	context() : _small_block_allocator(&_zone_allocator, this), _string_table(&_zone_allocator), _frame_allocator(&_zone_allocator) {
	} //}, _pile(&_zone_allocator) {}
	
	zone_allocator &get_zone_allocator() { return _zone_allocator; }
	small_block_allocator<context> &get_small_block_allocator() { return _small_block_allocator; }
	indexed_string::table &get_string_table() { return _string_table; }
	//pile *get_pile() { return &_pile; }
	
	page_allocator<> *get_frame_allocator()
	{
		return &_frame_allocator;
	}
	private:
	//pile _pile;
	zone_allocator _zone_allocator;
	small_block_allocator<context> _small_block_allocator;
	indexed_string::table _string_table;
	page_allocator<> _frame_allocator;
};
