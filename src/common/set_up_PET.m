function import_str = setup_PET(engine, alias)
    if isempty(engine)
        engine = 'STIR';
    end
    try
        eval(['libload_' lower(engine)])
    catch
        error('package %s not found\n', engine)
    end
    if nargin < 2
        import_str = ['import m' engine '.*'];
    else
        if ~strcmp(['m' engine], alias)
            filename = mfilename();
            filepath = mfilename('fullpath');
            l = length(filepath) - length(filename);
            path = filepath(1:l);
            copyfile([path '/+m' engine], [path '/+' alias], 'f')
        end
        import_str = ' ';
    end
end