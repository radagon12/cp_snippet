vector<ll> tree;

void segmentTree(ll index,ll l,ll r,vector<ll>& a)
{
	if(l == r)
	{
		tree[index] = a[l];
		return;
	}

	if(l > r)
	{
		tree[index] = INT_MAX;
		return;
	}

	ll mid = (l + r)/2;
	segmentTree(2*index + 1,l,mid,a);
	segmentTree(2*index + 2,mid + 1,r,a);

	tree[index] = min(tree[2 * index + 1],tree[2 * index + 2]);
}

void build(ll n,vector<ll>& a)
{
	tree.resize(4 * n);
	segmentTree(0,0,n-1,a);
}

ll update(ll index,ll l,ll r,ll q,ll val)
{
	if(l > r)
		return INT_MAX;

	if(q < l or q > r)
		return INT_MAX;
	
	if(l==r)
	{
		return tree[index] = val;
	}

	ll mid = (l + r)>>1;

	return tree[index] = min(update(2*index + 1,l , mid, q,val),update(2*index + 2,mid + 1,r,q,val));
}

ll query(ll index,ll l,ll r,ll ql,ll qr)
{
	if(l > r)
		return INT_MAX;

	if(ql <= l and r <= qr)
	{
		return tree[index];
	}

	if(qr < l or ql > r)
	{
		return INT_MAX;
	}

	ll mid = (l + r)/2;

	return min(query(2*index + 1,l ,mid,ql,qr), query(2*index + 2,mid + 1,r,ql,qr));
}
