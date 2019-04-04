void EnsureEqual(const string& left, const string& right)
{
	if (left != right)
	{
		string s = left + " != " + right;
		throw runtime_error(s);
	}
}