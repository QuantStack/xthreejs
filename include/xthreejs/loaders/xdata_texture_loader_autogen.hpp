#ifndef XTHREE_DATA_TEXTURE_LOADER_HPP
#define XTHREE_DATA_TEXTURE_LOADER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // data_texture_loader declaration
    //

    template<class D>
    class xdata_texture_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xdata_texture_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using data_texture_loader = xw::xmaterialize<xdata_texture_loader>;

    using data_texture_loader_generator = xw::xgenerator<xdata_texture_loader>;

    //
    // data_texture_loader implementation
    //

    template <class D>
    inline void xdata_texture_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xdata_texture_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xdata_texture_loader<D>::xdata_texture_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdata_texture_loader<D>::set_defaults()
    {
        this->_model_name() = "DataTextureLoaderModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xdata_texture_loader));
//}
#endif