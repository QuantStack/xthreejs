#ifndef XTHREE_DATA_TEXTURE_HPP
#define XTHREE_DATA_TEXTURE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xtexture_autogen.hpp"

namespace xthree
{
    //
    // data_texture declaration
    //

    template<class D>
    class xdata_texture : public xtexture<D>
    {
    public:

        using base_type = xtexture<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::vector<std::vector<double>>, derived_type, data);
        XPROPERTY(std::string, derived_type, minFilter, "NearestFilter", xenums::Filters);
        XPROPERTY(std::string, derived_type, magFilter, "NearestFilter", xenums::Filters);
        XPROPERTY(bool, derived_type, flipY, false);
        XPROPERTY(bool, derived_type, generateMipmaps, false);

    protected:

        xdata_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using data_texture = xw::xmaterialize<xdata_texture>;

    using data_texture_generator = xw::xgenerator<xdata_texture>;

    //
    // data_texture implementation
    //

    template <class D>
    inline void xdata_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(data, state, buffers);
        xw::set_patch_from_property(minFilter, state, buffers);
        xw::set_patch_from_property(magFilter, state, buffers);
        xw::set_patch_from_property(flipY, state, buffers);
        xw::set_patch_from_property(generateMipmaps, state, buffers);
    }

    template <class D>
    inline void xdata_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(data, patch, buffers);
        xw::set_property_from_patch(minFilter, patch, buffers);
        xw::set_property_from_patch(magFilter, patch, buffers);
        xw::set_property_from_patch(flipY, patch, buffers);
        xw::set_property_from_patch(generateMipmaps, patch, buffers);
    }

    template <class D>
    inline xdata_texture<D>::xdata_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdata_texture<D>::set_defaults()
    {
        this->_model_name() = "DataTextureModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xdata_texture));
//}
#endif