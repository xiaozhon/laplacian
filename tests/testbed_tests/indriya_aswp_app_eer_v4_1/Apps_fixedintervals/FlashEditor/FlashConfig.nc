interface FlashConfig<t> {
	command const t* read();
	command void write(const t*);
}
