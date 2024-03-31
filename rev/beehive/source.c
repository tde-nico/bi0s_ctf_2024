
undefined8 weird_function(longlong *key)

{
	bool flag;
	bool boolean;
	bool prev_bool;
	int iVar4;
	char *fmt;
	uint fmt_size;
	ulonglong *puVar5;
	int iVar6;
	ulonglong *next_elem;
	ulonglong shifted;
	longlong lVar9;
	ulonglong curr [4];
	longlong local_38;
	undefined8 local_30;
	undefined8 local_28;
	undefined8 local_20;
	undefined8 local_18;
	undefined8 local_10;
	undefined8 local_8;
	  
	local_8 = 0;
	local_10 = 0;
	local_18 = 0;
	local_20 = 0;
	local_28 = 0;
	local_30 = 0;
	local_38 = 0;
	lVar9 = *key;
	bpf_probe_read(&local_38,8,key + 1);
	if (local_38 != 0x31337) {
		return 0;
	}
	bpf_probe_read(&local_30,8,(void *)(lVar9 + 0x70));
	bpf_probe_read(&local_28,8,(void *)(lVar9 + 0x68));
	bpf_undef();
	bpf_trace_printk((char *)0x0,0x13);
	if (curr[0] != 0) {
		i = 1;
		curr_chunk = (ulonglong *)&DAT_ram_00000014;
		iVar6 = 0;
		flag = true;
		iVar4 = 0;
		prev_bool = false;
		do {
			boolean = true;
			if (curr[0] != 0x40) { // '@'
				boolean = prev_bool;
			}
			iVar6 += boolean;
			iVar4 += !boolean;
			if (0x20 < (iVar6 + iVar4)) { // length = 32
				return 0;
			}
			if (i == 0x1e) // length = 30 ?
				break;
			shifted = (curr[0] & 0xf0) >> 4 | (curr[0] & 0xf) << 4;		// circular shift 4
			shifted = shifted >> 2 & 0x33 | (shifted & 0x33) << 2;  // circular bitshift 2
			if (*curr_chunk != (shifted >> 1 & 0x55 | (shifted & 0x55) << 1)) { // circular bitshift 1
				flag = false;  // fail
			}
			curr_chunk = (ulonglong *)(curr_chunk + 4);
			next_elem = (ulonglong *)(curr + i);
			i++;
			curr[0] = *next_elem;
			prev_bool = boolean;
		} while (curr[0] != 0);
		if (!flag) { // success
			fmt = (char *)0x98;
			fmt_size = 0x12;
			goto LBB0_17;
		}
	}
	fmt = (char *)0x88;
	fmt_size = 0x10;
LBB0_17:
	bpf_trace_printk(fmt,fmt_size);
	return 0;
}



int v00000000000003AC[29] =
{
  86,
  174,
  206,
  236,
  250,
  44,
  118,
  246,
  46,
  22,
  204,
  78,
  250,
  174,
  206,
  204,
  78,
  118,
  44,
  182,
  166,
  2,
  70,
  150,
  12,
  206,
  116,
  150,
  118
};


