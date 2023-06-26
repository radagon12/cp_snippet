
vector<ll> tree,lazy;

void build(ll n,vector<ll>& a)
{
	tree.resize(4 * n);
	lazy.resize(4 * n);
}

void segmentTree(ll index,ll l,ll r,vector<ll>& a)
{
	if(l > r)
	{
		tree[index] = 0;
		return;
	}
	
	if(l == r)
	{
		tree[index] = a[l];
		return;
	}

	ll mid = (l + r)>>1;

	segmentTree(2*index+1,l,mid,a);
	segmentTree(2*index+2,mid+1,r,a);

	tree[index] = tree[2*index + 1] + tree[2*index + 2];
}

ll query(ll index,ll l,ll r,ll ql,ll qr)
{
	if(lazy[index])
	{
		tree[index] += (r - l + 1) * lazy[index];

		if(l != r)
		{
			lazy[2*index + 2] = lazy[2*index + 1] = lazy[index];
		}

		lazy[index] = 0;
	}

	if(ql > r or l > qr)
		return 0;

	if(ql <= l and r <= qr)
	{
		return tree[index];
	}

	int mid = (l + r)/2;

	return query(2*index + 1,l,mid,ql,qr) + query(2*index + 2,mid + 1,r,ql,qr);
}

void update(ll index,ll l,ll r,ll ql,ll qr,ll val)
{
	if(lazy[index])
	{
		tree[index] += (r - l + 1) * lazy[index];

		if(l != r)
		{
			lazy[2*index + 2] = lazy[2*index + 1] = lazy[index];
		}

		lazy[index] = 0;
	}

	if(ql > r or l > qr)
		return 0;

	if(ql <= l and r <= qr)
	{
		lazy[index] = val;
	}

	int mid = (l + r)/2;

	update(2*index + 1,l,mid,ql,qr,val);
	update(2*index + 2,mid + 1,r,ql,qr,val);

	tree[index] = tree[2*index + 1] + tree[2*index + 2];
}
